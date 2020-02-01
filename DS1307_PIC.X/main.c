/*
 * @file i2.c
 * @author xpress_embedo
 * @date 1 Feb, 2020
 * 
 * @brief Main File of the Project
 *
 */

#include "main.h"
#include "I2C.h"

void main(void) 
{
  I2C_Init(I2C_STANDARD_SPEED);
  Delay_ms(100);
  I2C_Start();
  I2C_Restart();
  I2C_Send(0x45);
  I2C_Stop();
  while(1);
  return;
}
