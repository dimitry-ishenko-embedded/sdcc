/*
 * Simulator of microcontrollers (pdk.cc)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
 *
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/

//#include "ddconfig.h"

//#include <ctype.h>
//#include <stdarg.h> /* for va_list */
//#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "i_string.h"

// prj
#include "globals.h"
//#include "pobjcl.h"

// sim
//#include "simcl.h"
#include "dregcl.h"

// local
#include "glob.h"
#include "pdkcl.h"
//#include "portcl.h"
//#include "regspdk.h"

/*******************************************************************/

/*
 * Base type of PDK controllers
 */

cl_pdk::cl_pdk(struct cpu_entry *IType, class cl_sim *asim) : cl_uc(asim) {
  type = IType;
  if (type->type == CPU_PDK13)
    PCmask= 0x3ff;
  if (type->type == CPU_PDK14)
    PCmask= 0x7ff;
  if (type->type == CPU_PDK15)
    PCmask= 0xfff;
}

int cl_pdk::init(void) {
  cl_uc::init(); /* Memories now exist */

  //set_xtal(8000000);

  // rom = address_space(MEM_ROM_ID);
  // ram = mem(MEM_XRAM);
  // ram = rom;

  // zero out ram(this is assumed in regression tests)
  // for (int i = 0x0; i < 0x8000; i++) {
  //   ram->set((t_addr)i, 0);
  // }

  return (0);
}

void cl_pdk::reset(void) {
  cl_uc::reset();
  sp_most = 0x00;

  PC = 0x0000;
  regs.a = 0;
  for (t_addr i = 0; i < io_size; ++i) {
    store_io(i, 0);
  }
}

const char *cl_pdk::id_string(void) {
  switch (type->type) {
    case CPU_PDK13:
      return("pdk13");
    case CPU_PDK14:
      return("pdk14");
    case CPU_PDK15:
      return("pdk15");
    default:
      return("unknown pdk");
  }
}

/*
 * Making elements of the controller
 */
/*
t_addr
cl_pdk::get_mem_size(enum mem_class type)
{
  switch(type)
    {
    case MEM_ROM: return(0x10000);
    case MEM_XRAM: return(0x10000);
    default: return(0);
    }
 return(cl_uc::get_mem_size(type));
}
*/

void cl_pdk::mk_hw_elements(void)
{
  // TODO: Add hardware stuff here.
  class cl_hw *h;
  cl_uc::mk_hw_elements();

  add_hw(h= new cl_dreg(this, 0, "dreg"));
  h->init();
}

class cl_memory_chip *c;

void cl_pdk::make_memories(void) {
  class cl_address_space *as;

  int rom_storage, ram_storage;
  switch (type->type) {
  case CPU_PDK13:
    rom_storage = 0x400;
    ram_storage = 0x40;
    break;
  case CPU_PDK14:
    rom_storage = 0x800;
    ram_storage = 0x80;
    break;
  case CPU_PDK15:
    rom_storage = 0x1000;
    ram_storage = 0x100;
    break;
  default:
    return;//__builtin_unreachable();
  }
  rom = as = new cl_address_space("rom", 0, rom_storage, 16);
  as->init();
  address_spaces->add(as);
  ram = as = new cl_address_space("ram", 0, ram_storage, 8);
  as->init();
  address_spaces->add(as);
  regs8 = as = new cl_address_space("regs8", 0, io_size + 1, 8);
  as->init();
  address_spaces->add(as);

  {
    class cl_address_decoder *ad;
    class cl_memory_chip *chip;

    chip = new cl_chip16("rom_chip", rom_storage, 16);
    chip->init();
    memchips->add(chip);

    ad = new cl_address_decoder(as = address_space("rom"), chip, 0, rom_storage-1, 0);
    ad->init();
    as->decoders->add(ad);
    ad->activate(0);

    chip = new cl_chip16("ram_chip", ram_storage, 8);
    chip->init();
    memchips->add(chip);

    ad = new cl_address_decoder(as = address_space("ram"), chip, 0, ram_storage-1, 0);
    ad->init();
    as->decoders->add(ad);
    ad->activate(0);

    chip = new cl_chip16("io_chip", io_size, 8);
    chip->init();
    memchips->add(chip);

    ad = new cl_address_decoder(as = address_space("regs8"), chip, 0, io_size-1, 0);
    ad->init();
    as->decoders->add(ad);
    ad->activate(0);
  }
  {
    // extra byte of the IO memory will point to the A register just for the debugger
    regs8->get_cell(io_size)->decode(&(regs._a));
  }

  vars->add("flag", regs8, 0, 7, 0, "Flags");
  vars->add("sp", regs8, 1, 7, 0, "Stack Pointer");
}

/*
 * Help command interpreter
 */

struct dis_entry *cl_pdk::dis_tbl(void) {
  switch (type->type) {
  case CPU_PDK13:
    return (disass_pdk_13);
  case CPU_PDK14:
    return (disass_pdk_14);
  case CPU_PDK15:
    return (disass_pdk_15);
  default:
    return NULL;//__builtin_unreachable();
  }
}

/*struct name_entry *
cl_pdk::sfr_tbl(void)
{
  return(0);
}*/

/*struct name_entry *
cl_pdk::bit_tbl(void)
{
  //FIXME
  return(0);
}*/

int cl_pdk::inst_length(t_addr /*addr*/) {
  return 1;
}
int cl_pdk::inst_branch(t_addr addr) {
  int b;

  get_disasm_info(addr, NULL, &b, NULL, NULL);

  return b;
}

bool cl_pdk::is_call(t_addr addr) {
  struct dis_entry *e;

  get_disasm_info(addr, NULL, NULL, NULL, &e);

  return e ? (e->is_call) : false;
}

int cl_pdk::longest_inst(void) { return 1; }

const char *cl_pdk::get_disasm_info(t_addr addr, int *ret_len, int *ret_branch,
                                    int *immed_offset,
                                    struct dis_entry **dentry) {
  const char *b = NULL;
  int immed_n = 0;
  int start_addr = addr;
  struct dis_entry *instructions;

  switch (type->type) {
      /* Dispatch to appropriate pdk port. */
      case CPU_PDK13:
        instructions = disass_pdk_13;
        break;

      case CPU_PDK14:
        instructions = disass_pdk_14;
        break;

      case CPU_PDK15:
        instructions = disass_pdk_15;
        break;

      default:
        return "";//__builtin_unreachable();
  }

  uint code = rom->get(addr++);
  int i = 0;
  while ((code & instructions[i].mask) != instructions[i].code &&
         instructions[i].mnemonic)
    i++;
  dis_entry *dis_e = &instructions[i];
  b = instructions[i].mnemonic;

  if (ret_branch) {
    *ret_branch = dis_e->branch;
  }

  if (immed_offset) {
    if (immed_n > 0)
      *immed_offset = immed_n;
    else
      *immed_offset = (addr - start_addr);
  }

  if (ret_len) *ret_len = 1;

  if (dentry) *dentry = dis_e;

  return b;
}

char *cl_pdk::disass(t_addr addr)
{
  chars work, temp;
  const char *b;
  int len = 0;
  int immed_offset = 0;
  struct dis_entry *dis_e;
  bool first= true;
  
  work= "";

  b = get_disasm_info(addr, &len, NULL, &immed_offset, &dis_e);

  if (b == NULL)
    {
      return (strdup("UNKNOWN/INVALID"));
    }

  while (*b)
    {
      if ((*b == ' ') && first)
	{
	  first= false;
	  while (work.len() < 6) work.append(' ');
	}
      if (*b == '%')
	{
	  temp= "";
	  b++;
	  uint code = rom->get(addr) & ~(uint)dis_e->mask;
	  switch (*(b++))
	    {
	    case 'k':  // k    immediate addressing
	      temp.format("#0x%x", code);
	      break;
	    case 'm':  // m    memory addressing
	      if (*b == 'n') {
		switch (type->type) {
		case CPU_PDK13:
		  code &= 0x0F;
		  break;
		case CPU_PDK14:
		  code &= 0x3F;
		  break;
		case CPU_PDK15:
		  code &= 0x7F;
		  break;
		default:
		  ;//__builtin_unreachable();
		}
		++b;
	      }
	      temp.format("0x%x", code);
	      break;
	    case 'i':  // i    IO addressing
	      // TODO: Maybe add pretty printing.
	      if (*b == 'n') {
		switch (type->type) {
		case CPU_PDK13:
		  code &= 0x1F;
		  break;
		case CPU_PDK14:
		  code &= 0x3F;
		  break;
		case CPU_PDK15:
		  code &= 0x7F;
		  break;
		default:
		  ;//__builtin_unreachable();
		}
		
		++b;
	      }
	      temp.format("[0x%x]", code);
	      break;
	    case 'n':  // n    N-bit addressing
	      uint n;
	      switch (type->type) {
	      case CPU_PDK13:
		n = (code & 0xE0) >> 5;
		break;
	      case CPU_PDK14:
		n = (code & 0x1C0) >> 6;
		break;
	      case CPU_PDK15:
		n = (code & 0x380) >> 7;
		break;
	      default:
		n= 0;//__builtin_unreachable();
	      }
	      temp.format("#0x%x", n);
	      break;
	    default:
	      temp= "%?";
	      break;
	    }
	  work+= temp;
	}
      else
	work+= *(b++);
    }

  return strdup(work.c_str());
}

void cl_pdk::print_regs(class cl_console_base *con) {
  con->dd_color("answer");
  con->dd_printf("A= 0x%02x(%3d)\n", regs.a, regs.a);
  con->dd_printf("Flag= 0x%02x(%3d)  \n", get_flags(), get_flags());
  con->dd_printf("SP= 0x%02x(%3d)\n", get_SP(), get_SP());

  print_disass(PC, con);
}

/*
 * Execution
 */

int cl_pdk::exec_inst(void)
{
  t_mem code;

  instPC= PC;
  if (fetch(&code)) {
    return (resBREAKPOINT);
  }
  tick(1);

  int status = execute(code);
  if (status == resINV_INST)
    {
      //PC = instPC;//rom->inc_address(PC, -1);
      return (resINV_INST);
    }
  return (status);
}

/* End of pdk.src/pdk.cc */
