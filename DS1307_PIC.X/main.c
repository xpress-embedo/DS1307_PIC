/*
 * File:   main.c
 * Author: xpress_embedo
 *
 * Created on 1 February, 2020, 3:41 AM
 */


#include "main.h"

void main(void) 
{
  TRISB = 0x00;
  while(1)
  {
    LATB = 0x55;
    __delay_ms(1000);
    LATB = 0xAA;
    __delay_ms(1000);
  }
  return;
}
