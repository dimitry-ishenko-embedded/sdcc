;-------------------------------------------------------------------------------
; crt0.s for Rabbit 2000
;
; Copyright (c) 2000 Michael Hope
; Copyright (c) 2020 Philipp Klaus Krause
; Copyright (c) 2023 Dimitry Ishenko <dimitry (dot) ishenko (at) (gee) mail (dot) com>
;
; This library is free software: you can redistribute it and/or modify it under
; the terms of the GNU General Public License as published by the Free Software
; Foundation, either version 3 of the License, or (at your option) any later
; version.
;
; This library is distributed in the hope that it will be useful, but WITHOUT
; ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
; FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
; details.
;
; You should have received a copy of the GNU General Public License along with
; this program. If not, see <https://www.gnu.org/licenses/>.
;
; Additional permission under GNU GPL version 3 section 7
;
; As a special exception, if you link this library with other files to produce
; an executable, this library does not by itself cause the resulting executable
; to be covered by the GNU General Public License. This exception does not
; however invalidate any other reasons why the executable file might be covered
; by the GNU Public License.
;-------------------------------------------------------------------------------
    .module crt0
    .globl _main
    .globl ___sdcc_external_startup

GCSR     .equ 0x0000
STACKSEG .equ 0x0011
DATASEG  .equ 0x0012
SEGSIZE  .equ 0x0013
MB0CR    .equ 0x0014
MB2CR    .equ 0x0016

DATA     .equ 0x8000
STACK    .equ 0xa000
INT_IVT  .equ 0xdc00
EXT_IVT  .equ 0xde00

; RABBIT 3000A                        physical         1MB
; MEMORY MAP                          0xfffff +-------------+
;                                             |             |
;                                             |             |
;                                             |             |
;                                                    ...
;                                             |             |
;     logical                                 |             |
;     0xffff +-------------+                  | quadrant #3 |
;            |             |          0xc0000 +-------------+
;            | XPC segment |                  |             |
;            |             |                  |             |            RAM
;     0xe000 +-------------+                  |             |          +-------------+
;            | unused      |                         ...               |             |
;     0xdf00 +-------------+                  |             |          | /CS1        |
;            | extern IVT  |                  |             |          | /OE1        |
;     0xde00 +-------------+                  | quadrant #2 |          | /WE1        |
;            |             |      +-> 0x80000 +-------------+ (5) ---> +-------------+
;            | intern IVT  |      |           |             |
;     0xdc00 +-------------+      |           |             |
;            | stack       |      |           |             |
;            |             |      |                  ...
;            |             |      |           |             |
;            |             |      |           |             |
;            | global data |      |           | quadrant #1 |
; (1) 0xa000 +-------------+ (3) -+   0x40000 +-------------+
;            |             |                  |             |
;            |             |                  |             |            Flash
;            |             |                  |             |          +-------------+
; (1) 0x8000 |             | (2)                     ...               |             |
;            |             |                  |             |          | /CS0        |
;            | code and    |                  |             |          | /OE0        |
;            | const data  |                  | quadrant #0 |          | /WE0        |
;     0x0000 +-------------+ -------> 0x00000 +-------------+ (4) ---> +-------------+
;
; notes:
; (1) SEGSIZE
; (2) DATASEG
; (3) STACKSEG
; (4) MB0CR
; (5) MB2CR

    .area _HEADER (ABS)
    .org 0

; map memory quadrants #0 and #2
    ld a, #0x08             ; /CS0, /OE1, 4ws
    ioi
    ld (MB0CR), a           ; read-only Flash @ physical address 0x00000

    ld a, #0x05             ; /CS1, /OE1, /WE1, 4ws
    ioi
    ld (MB2CR), a           ; read/write RAM @ physical address 0x80000

; set stack and data boundaries
    ld a, #((STACK >> 8) | (DATA >> 12))
    ioi
    ld (SEGSIZE), a

; map stack segment to the physical address 0x80000 (start of RAM)
; this segment is used for the interrupt vector tables (IVT), stack and global data
    ld a, #((0x80000 - STACK) >> 12)
    ioi
    ld (STACKSEG), a
    ld sp, #INT_IVT         ; set stack pointer below the internal IVT

; leave data segment mapped to 0x00000 since it is not being used
    ld a, #0x00
    ioi
    ld (DATASEG), a

; map internal and external IVT
    ld a, #(INT_IVT >> 8)
    ld iir, a
    ld a, #(EXT_IVT >> 8)
    ld eir, a

    call ___sdcc_external_startup
    or a, a
    jr nz, dont_gsinit

    call gsinit

dont_gsinit:
    call _main
    jp _exit

    .org 0x100

    .area _HOME
    .area _CODE
    .area _INITIALIZER
    .area _GSINIT
    .area _GSFINAL

    .area _DATA
    .area _INITIALIZED
    .area _BSEG
    .area _BSS
    .area _HEAP

    .area _CODE
_exit::
    ld a, #0
    rst #0x28
1$: jr 1$

    .area _GSINIT
gsinit::
fill_zero:
    ld bc, #l__DATA
    ld a, b
    or a, c
    jr z, fill_data
    ld hl, #s__DATA
    ld (hl), #0x00
    dec bc
    ld a, b
    or a, c
    jr z, fill_data
    ld e, l
    ld d, h
    inc de
zero_loop:
    ldi ; work around ldir wait state bug
    jp lo, zero_loop

fill_data:
    ld bc, #l__INITIALIZER
    ld a, b
    or a, c
    jr z, fill_done
    ld de, #s__INITIALIZED
    ld hl, #s__INITIALIZER
fill_loop:
    ldi ; work around ldir wait state bug
    jp lo, fill_loop

fill_done:
    .area _GSFINAL
    ret
