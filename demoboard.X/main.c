/* 
 * File:   main.c
 * Author: dconcors
 *
 * Created on February 28, 2015, 4:21 PM
 */

#include "audio.h"

#include <xc.h>
#define FCY 16000000UL // Instruction cycle frequency, Hz
#include <libpic30.h>
_CONFIG1(FWDTEN_OFF & GWRP_OFF & GCP_OFF & JTAGEN_OFF)
_CONFIG2(POSCMOD_HS & FCKSM_CSDCMD & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2)
_CONFIG3(ALTPMP_ALTPMPEN & SOSCSEL_EC)


/*
 * 
 */

extern struct song *current_song;

int main(int argc, char** argv) {

    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSF = 0x0000;
    ANSG = 0x0000;
    TRISB = 0x0000;
    
    audio_setup();
    while(1);
    return (0);
}

