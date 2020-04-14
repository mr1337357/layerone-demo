#include "gpio.h"

#include <xc.h>
#define FCY 16000000UL // Instruction cycle frequency, Hz
#include <libpic30.h>

void ledon()
{
    PORTB|=0x0010;
}

void ledoff()
{
    PORTB&=0xFFEF;
}

void gpio_init()
{
    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSF = 0x0000;
    ANSG = 0x0000;
    TRISB = 0;
}