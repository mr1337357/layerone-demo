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

char line[80];

int16_t tsin;
int16_t tcos;

void rotate(int16_t *x,int16_t *y,uint16_t angle)
{
    int16_t tx;
    int16_t ty;
    tx = ((int32_t)tcos*(*x)-(int32_t)tsin*(*y))>>14;
    ty = ((int32_t)tsin*(*x)+(int32_t)tcos*(*y))>>14;
    *x=tx;
    *y=ty;
}

int16_t img2coord(uint16_t img)
{
    int16_t coord;
    coord=img;
    coord-=(LOGO_WIDTH/2);
    coord*=137;
    return coord;
}

uint16_t coord2gfx(int16_t coord)
{
    uint16_t gfx;
    coord/=137;
    coord+=160;
    gfx=coord;
    return gfx;
}

void drawlogo(uint16_t angle)
{
    int16_t x;
    int16_t y;
    uint16_t i;
    uint16_t j;
    uint16_t h;
    uint16_t v;
    uint16_t c;
    tcos = fcos(angle);
    tsin = fsin(angle);
    for(j=0;j<LOGO_HEIGHT;j++)
    {
        for(i=0;i<LOGO_WIDTH;i++)
        {
            c = logo[i+(LOGO_WIDTH)*j]; //grab a pixel
            /*if(c==0)
            {
                continue;
            }*/
            //x=img2coord(i);
            x=((int16_t)i-LOGO_WIDTH/2)*137;
            y=((int16_t)j-LOGO_WIDTH/2)*137;
            //y=img2coord(j);
            rotate(&x,&y,angle); //rotate the pixel's coordinates
            //h=coord2gfx(x);
            //v=coord2gfx(y);
            h=(x/137+160);
            v=(y/137+200);
            if(c==0)
            {
                gfx_drawpixel(h,v,(h/29)+4);
            }
            else
            {
                gfx_drawpixel(h,v,c);
            }
        }
    }
}

void drawbg()
{
    int16_t x;
    int16_t y;
    for(y=1;y<400;y++)
    {
        for(x=1;x<319;x++)
        {
            
            gfx_drawpixel(x,y,(x/29)+4);
        }
    }
}

int main(int argc, char** argv) {
    uint16_t i;
    gpio_init();
    gfx_init();
    drawbg();
    audio_setup();

    while(1)
    {
        drawlogo(i);
        i+=2;
        if(i==360)
        {
            i=0;
        }
        //gpu_vsync();
        //rotate_colors();
    }
    return (0);
}

