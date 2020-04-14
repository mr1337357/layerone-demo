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
#include "mandelbrot.h"

#pragma config FWDTEN = OFF , GWRP = OFF , GCP = OFF , JTAGEN = OFF
#pragma config POSCMOD = HS , FCKSM = CSDCMD , FNOSC = PRIPLL , PLL96MHZ = ON , PLLDIV = DIV2
#pragma config ALTPMP = ALTPMPEN , SOSCSEL = EC

/*
 * 
 */


extern struct song *current_song;

void drawpixel(uint16_t x,uint16_t y,uint16_t color)
{
    color&=0x000F;
    if(x&1)
    {
        color<<=4;
    }
    x>>=1;
    GFXDisplayBuffer[x+160*y]|=color;
}

void mandeldraw()
{
    complex_t c;
    uint16_t color;
    uint16_t x;
    uint16_t y;
    c.imag=0x7FFF;
    for(y=0;y<240;y++)
    {
        c.real=0x8000;
        for(x=0;x<319;x++)
        {
            color = iterate(&c);
            c.real+=204;
            drawpixel(x,y,color>>4);
        }
        c.imag-=274;
    }
}

void set_color()
{
    uint16_t c;
    uint16_t i;
    for(i=0;i<16;i++)
    {
        if(i<8)
        {
            c=0x0080*i;
        }
        else
        {
            c=0x07E0+0x2000*(i-8);
        }
        gpu_clut_set(i, c);
    }
}

void set_bw()
{
    uint16_t c;
    uint16_t i;
    for(i=0;i<16;i++)
    {
        c=i*0x1082;
        gpu_clut_set(i, c);
    }
}

int main(int argc, char** argv) {
    uint16_t x;
    uint16_t y;
    volatile uint16_t i;
    volatile uint16_t offset=0;
    uint16_t colors[16]=
    {
        0xF800, 0xFB00, 0xfde0, 0xdfe0,
        0x87E0, 0x27E0, 0x07E8, 0x07F3,
        0x07FF, 0x04FF, 0x021F, 0x401F,
        0x801F, 0xD81F, 0xF817, 0xF80C,

        
    };
    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSF = 0x0000;
    ANSG = 0x0000;
    TRISB = 0x0000;
    
    
    
    gpu_init();
    gpu_set_res(RES_320x240, SINGLEBUFFERED, BPP_4);
    gpu_config_clut();
    gpu_clear_all_fb();  
    set_bw();

    audio_setup();
    
    uart_init();
    uart_puts("This was a triumph\r\n");
    
    for(i=1;i<16;i++)
    {
        gpu_clut_set(i, colors[i]);
    }
    mandeldraw();
    for(x=1;x<16;x++)
    {
        for(y=0;y<16;y++)
        {
            drawpixel(x+160,y+120,x);
        }
    }
    
    i=1;
    //set_color();
    //while(1);
    while(1)
    {
        gpu_flip_fb();
        gpu_flip_fb();
        //while(hlines<120);
        for(i=1;i<16;i++)
        {
            gpu_clut_set(i, colors[(i+offset)%15]);
        }
        offset++;
    }
    return (0);
}

