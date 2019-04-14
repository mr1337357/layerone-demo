/* 
 * File:   main.c
 * Author: dconcors
 *
 * Created on February 28, 2015, 4:21 PM
 */

#include <xc.h>
#define FCY 16000000UL // Instruction cycle frequency, Hz
#include <libpic30.h>
 
#include "audio.h"
#include "gfx.h"

#pragma config FWDTEN = OFF , GWRP = OFF , GCP = OFF , JTAGEN = OFF
#pragma config POSCMOD = HS , FCKSM = CSDCMD , FNOSC = PRIPLL , PLL96MHZ = ON , PLLDIV = DIV2
#pragma config ALTPMP = ALTPMPEN , SOSCSEL = EC

/*
 * 
 */

extern struct song *current_song;

int main(int argc, char** argv) {
    uint16_t x;
    uint16_t y;
    int i;
    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSF = 0x0000;
    ANSG = 0x0000;
    TRISB = 0x0000;
    
    gpu_init();
    gpu_set_res(RES_320x480, SINGLEBUFFERED, BPP_2);
    gpu_config_clut();
    gpu_clear_all_fb();  
    
    gpu_clut_set(0, rgb_2_565(0,0,0)); 
    gpu_clut_set(1, rgb_2_565(0x40,0x40,0x40));
    gpu_clut_set(2, rgb_2_565(0x80,0x80,0x80));
    gpu_clut_set(3, rgb_2_565(0xC0,0xC0,0xC0));

    audio_setup();
    x=0;
    y=0;
    for(i=0;i<240;i++)
    {
            GFXDisplayBuffer[80*i]  =0xE4;
    }
    while(1)
    {
        rcc_color(1);
        x++;
        if(x==gfx.hres-1)
        {
            x=0;
            y++;
        }
        //gpu_flip_fb();
        if(hlines==0)
        {
            gpu_clut_set(0, rgb_2_565(0,0,0)); 
            gpu_clut_set(1, rgb_2_565(0x40,0x40,0x40));
            gpu_clut_set(2, rgb_2_565(0x80,0x80,0x80));
            gpu_clut_set(3, rgb_2_565(0xC0,0xC0,0xC0));
        }
        if(hlines==240)
        {
            gpu_clut_set(0, rgb_2_565(0,0,0)); 
            gpu_clut_set(1, rgb_2_565(255,0,0));
            gpu_clut_set(2, rgb_2_565(0,255,0));
            gpu_clut_set(3, rgb_2_565(0,0,255));
            gpu_flip_fb();
        }
    }
    return (0);
}

