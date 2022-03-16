/*
   20131127-1.c from the execute part of the gcc torture suite.
 */

#include <testfwk.h>

#ifdef __SDCC
#pragma std_c99
#endif

/* PR middle-end/59138 */
/* Testcase by John Regehr <regehr@cs.utah.edu> */

struct S0 {
  int f0;
  int f1;
  int f2;
  short f3;
};

short a = 1;

struct S0 b = { 1 }, c, d, e;
#ifndef __SDCC_mcs51 // mcs51 does not yet support returning struct
struct S0 fn1() { return c; }

void fn2 (void)
{
  b = fn1 ();
  a = 0;
  d = e;
}
#endif
void
testTortureExecute (void)
{
#ifndef __SDCC_mcs51 // mcs51 does not yet support returning struct
  fn2 ();
  if (a != 0)
    ASSERT (0);
#endif
}

