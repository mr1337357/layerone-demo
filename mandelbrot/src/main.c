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
#include "uart.h"

#pragma config FWDTEN = OFF , GWRP = OFF , GCP = OFF , JTAGEN = OFF
#pragma config POSCMOD = HS , FCKSM = CSDCMD , FNOSC = PRIPLL , PLL96MHZ = ON , PLLDIV = DIV2
#pragma config ALTPMP = ALTPMPEN , SOSCSEL = EC

/*
 * 
 */

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

void draw4px(uint16_t x,uint16_t y,uint16_t pixels)
{
   __eds__ uint16_t *gfxbuf;
   gfxbuf = (__eds__ uint16_t *)GFXDisplayBuffer;
   x>>=2;
   drawpixel(x,y,pixels);
   //drawpixel(x+1,y,pixels>>4);
   //drawpixel(x+2,y,pixels>>8);
   //drawpixel(x+3,y,pixels>>12);
   gfxbuf[x+80*y]|=pixels;
}

void mandeldraw()
{
    complex_t c;
    uint16_t color;
    uint16_t pixels;
    uint16_t x;
    uint16_t y;
    c.imag=0x7FFF;
    for(y=0;y<240;y++)
    {
        c.real=0x8000;
        for(x=0;x<319;x+=4)
        {
            color = iterate(&c);
            pixels>>=4;
            color <<= 8;
            color &=0xF000;
            pixels|=color;
            c.real+=204;
            color = iterate(&c);
            pixels>>=4;
            color <<= 8;
            color &=0xF000;
            pixels|=color;
            c.real+=204;
            color = iterate(&c);
            pixels>>=4;
            color <<= 8;
            color &=0xF000;
            pixels|=color;
            c.real+=204;
            color = iterate(&c);
            pixels>>=4;
            color <<= 8;
            color &=0xF000;
            pixels|=color;
            c.real+=204;
            draw4px(x,y,pixels);
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

    uart_init();
    
    for(i=1;i<16;i++)
    {
        gpu_clut_set(i, colors[i]);
    }
    //draw4px(16,16,0x5555);
    //draw4px(20,16,0x4444);
    mandeldraw();

    while(1)
    {

    }
    return (0);
}

