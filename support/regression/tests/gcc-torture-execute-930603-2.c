/*
   930603-2.c from the execute part of the gcc torture suite.
 */

#include <testfwk.h>

#ifdef __SDCC
#pragma std_c99
#endif

int w[2][2];

void
f (void)
{
  int i, j;

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      if (i == j)
	w[i][j] = 1;
}

void
testTortureExecute (void)
{
  f ();
  ASSERT(!(w[0][0] != 1 || w[1][1] != 1 || w[1][0] != 0 || w[0][1] != 0));
  return;
}

