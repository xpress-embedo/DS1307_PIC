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

/* Local Variables */
static uint32_t millisecond = 0;

/* Local Function */
void timer0_init( void );
void system_init( void );

/* Start From Here*/
void main(void) 
{
  char lcd_msg[LCD_BUFFER_LEN] = {0};
  uint32_t timestamp = 0;
  system_init();
  sprintf(lcd_msg, "Embedded");
  LCD_Print_Line (0, lcd_msg);
  sprintf(lcd_msg, "      Laboratory");
  LCD_Print_Line (1, lcd_msg);
  LCD_Update ();
  Delay_ms(2000);
  while(1)
  {
    // Task-1
    if( millis() - timestamp > 1000ul )
    {
      timestamp = millis();
    }
  }
  return;
}

/* Function Definitions */

/**
 * @breif Initialize the system
 */
void system_init( void )
{
  // Initialize 1ms Timer
  timer0_init ();
  // Initialize I2C
  I2C_Init(I2C_STANDARD_SPEED);
  // Initialize LCD
  LCD_Init();
  Delay_ms(100);
}

/**
 * @brief Counts milliseconds till startup
 * @return This function returns the number of milliseconds elapsed till the 
 * system is powered up.
 */
uint32_t millis( void )
{
  uint32_t time = 0;
  GIE = 0;
  time = millisecond;
  GIE = 1;
  return time;
}

/**
 * @brief Initialize Timer0 Module to generate 1ms interrupt
 */
void timer0_init( void )
{
  // Code Generated Using mikroC Timer Calculator
  T0CON	= 0x88;
  TMR0H	= 0xD1;
  TMR0L = 0x20;
  ENABLE_INT();
  TMR0IE = 1;
}

/**
 * PIC18F Interrupt Service Routine
 */
void __interrupt() ISR_ROUTINE( void )
{
  if( TMR0IF )
  {
    TMR0IF = 0;
    TMR0H	= 0xD1;
    TMR0L = 0x20;
    millisecond++;
  }
}
