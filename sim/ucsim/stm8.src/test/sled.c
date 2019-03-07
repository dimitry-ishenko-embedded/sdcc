// Source code under CC0 1.0
#include <stdint.h>

#include "stm8.h"

#define PD GPIOD

unsigned int clock(void)
{
  unsigned char h = TIM1->cntrh;
  unsigned char l = TIM1->cntrl;
  return((unsigned int)(h) << 8 | l);
}

unsigned int last= 0;

void main(void)
{
  unsigned int now;
  CLK->ckdivr = 0x00; // Set the frequency to 16 MHz

  // Configure timer
  // 1000 ticks per second
  TIM1->pscrh = 0x3e;
  TIM1->pscrl = 0x80;
  // Enable timer
  TIM1->cr1 = 0x01;
  
  PD->ddr = 0x01;
  PD->cr1 = 0x01;

  for(;;)
    {
      now= clock();
      if (now - last > 500)
	{
	  if (PD->odr & 1)
	    PD->odr&= ~1;
	  else
	    PD->odr|= 1;
	  last= now;
	}
    }
}
