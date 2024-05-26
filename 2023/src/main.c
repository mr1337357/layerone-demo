/* 
 * File:   main.c
 * Author: dconcors
 *
 * Created on February 28, 2015, 4:21 PM
 */

#include <xc.h>
#define FCY 16000000UL // Instruction cycle frequency, Hz
#include <libpic30.h>
#include <stdio.h>
#include "p24FJ256DA206.h"

#include "gfx.h"
#include "uart.h"
#include "gpu.h"
#include "../assets/c64font.h"
#include "basic_functions.h"

#pragma config FWDTEN = OFF , GWRP = OFF , GCP = OFF , JTAGEN = OFF
#pragma config POSCMOD = HS , FCKSM = CSDCMD , FNOSC = PRIPLL , PLL96MHZ = ON , PLLDIV = DIV2
#pragma config ALTPMP = ALTPMPEN , SOSCSEL = EC

int debug_level = 0;

uint8_t font[] = { c64font_DATA };

uint8_t system_state = 0;

int main(int argc, char** argv)
{
    uart_init();
    gfx_init();
    gfx_singlebuffer();
    set_bw();
    program_init(&GFXDisplayBuffer[38400+sizeof(font)],38400-sizeof(font));
    font_load(font,sizeof(font));
    variable_init();
    system_state = 1;
    fprintf(stdout,"PapayaSoft Basic\n");
    fprintf(stdout,"autorun in 5 seconds...\n");
    while(1)
    {
        switch(system_state)
        {
            case 1:
                system_state = editor_run();
                break;
            case 2:
                break;
        }
    }
    return 0;
}

