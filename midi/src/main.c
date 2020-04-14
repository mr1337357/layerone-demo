/* 
 * File:   main.c
 * Author: dconcors
 *
 * Created on February 28, 2015, 4:21 PM
 */

#include <xc.h>
#define FCY 16000000UL // Instruction cycle frequency, Hz
#include <libpic30.h>

#include "uart.h"
#include "gpio.h"
#include "gfx.h"
#include "logo.h"
#include "fixed.h"
#include "audio.h"

#pragma config FWDTEN = OFF , GWRP = OFF , GCP = OFF , JTAGEN = OFF
#pragma config POSCMOD = HS , FCKSM = CSDCMD , FNOSC = PRIPLL , PLL96MHZ = ON , PLLDIV = DIV2
#pragma config ALTPMP = ALTPMPEN , SOSCSEL = EC

int main(int argc, char** argv)
{
   uint8_t cmd;
   uint8_t k;
   uint8_t v;
   gpio_init();
   uart_init();
   audio_setup();
   uart_puts("test\r\n");
   while(1)
   {
      cmd = uart_rx();
      if(!(cmd&0x80))
      {
         continue;
      }
      k = uart_rx();
      v = uart_rx();
      process_midi(cmd,k,v);
      
   }
   return (0);
}

