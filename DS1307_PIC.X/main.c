/*
 * @file i2.c
 * @author xpress_embedo
 * @date 1 Feb, 2020
 * 
 * @brief Main File of the Project
 *
 */

#include "main.h"
#include "lcd_16x2.h"
#include "I2C.h"

/* Private Variables */
static uint32_t millisecond = 0;

void main(void) 
{
  I2C_Init(I2C_STANDARD_SPEED);
  LCD_Init();
  Delay_ms(100);
  LCD_Write_Text ("Hello World");
  I2C_Start();
  I2C_Restart();
  I2C_Send(0x45);
  I2C_Stop();
  while(1);
  return;
}


uint32_t millis( void )
{
  uint32_t time = 0;
  GIE = 0;
  time = millisecond;
  GIE = 1;
  return time;
}

// Timer0
//Prescaler 1:16; TMR0 Preload = 6; Actual Interrupt Time : 1 ms
void timer0_init( void )
{
  T0CON	 = 0xC3;
  TMR0L	 = 0x06;
  ENABLE_INT();
  TMR0IE = 1;
}

void __interrupt() ISR_ROUTINE( void )
{
  if( TMR0IF )
  {
    TMR0IF = 0;
    TMR0L	 = 0x06;
    millisecond++;
  }
}
