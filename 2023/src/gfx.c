#include <stdio.h>
#include "gpu.h"

static uint16_t cursor_x;
static uint16_t cursor_y;
static uint32_t slots = 0;
static uint16_t gfxpage = 0;
static __eds__ uint8_t *drawbuf = GFXDisplayBuffer;
static __eds__ uint8_t *backbuf = GFXDisplayBuffer;

void gfx_singlebuffer()
{
   drawbuf = &GFXDisplayBuffer[0];
   backbuf = &GFXDisplayBuffer[0];
   rcc_set_fb_dest(&GFXDisplayBuffer[0]);
   rcc_set_fb_src(&GFXDisplayBuffer[38400]);
   gpu_set_fb(&GFXDisplayBuffer[0]);
}

void screen_putch(char c)
{
    if(c == '\n')
    {
        cursor_x = 16;
        cursor_y += 8;
        if(cursor_y == 232)
        {
            rcc_scroll();
            cursor_y = 224;
        }
        return;
    }
    else if(c >= ' ' && c <= '~')
    {
        c-=' ';
    }
    else if(c == '\b')
    {
        if(cursor_x > 16)
        {
            cursor_x -= 8;
            rcc_blit(0,cursor_x,cursor_y,8,8);
        }
        return;
    }
    if(c < 95)
    {
        rcc_blit(c*64,cursor_x,cursor_y,8,8);
    }
    cursor_x+=8;
    if(cursor_x == 320)
    {
        cursor_x = 16;
        cursor_y += 8;
    }
    if(cursor_y == 232)
    {
        rcc_scroll();
        cursor_y = 224;
    }
    return;
    
}

//copy sprites from flash to the screen just beyond the overscan
void font_load(const uint8_t *font,int len)
{
   uint16_t i;
   for(i=0;i<len;i++)
   {
      //GFXDisplayBuffer[i]=font[i];
      GFXDisplayBuffer[38400+i]=font[i];
   }
}

void sprite_clear(uint8_t slot)
{
   slots&=1<<slot;
}

//load a sprite from overscan into the frame
void sprite_blit(uint8_t slot,uint8_t x,uint8_t y)
{
   rcc_blit(slot*256,x,y,16,16);
}

void gfx_clear_screen()
{
   rcc_color(0);
   rcc_rec(1,1,318,217);
   cursor_x = 16;
   cursor_y = 16;
}

void gfx_flip()
{
   gpu_flush();
   gpu_vsync();
   if(gfxpage)
   {
      drawbuf = &GFXDisplayBuffer[0];
      backbuf = &GFXDisplayBuffer[38400];
      rcc_set_fb_dest(&GFXDisplayBuffer[0]);
      gpu_set_fb(&GFXDisplayBuffer[38400]);
      gfxpage = 0;
   }
   else
   {
      drawbuf = &GFXDisplayBuffer[38400];
      backbuf = &GFXDisplayBuffer[0];
      rcc_set_fb_dest(&GFXDisplayBuffer[38400]);
      gpu_set_fb(&GFXDisplayBuffer[0]);
      gfxpage = 1;
   }
}
   
void gfx_drawpixel(uint16_t x,uint16_t y,uint8_t color)
{
    uint8_t mask = 0x0F;
    color &= 0x0F;
    if(x&1)
    {
        color<<=4;
        mask<<=4;
    }
    x>>=1;
    drawbuf[x+160*y]&=~mask;
    drawbuf[x+160*y]|=color;
}

uint8_t gfx_getpixel(uint16_t x,uint16_t y)
{
//   uint8_t pxl = drawbuf[(x>>1)+160*y];
   uint8_t pxl = backbuf[(x>>1)+160*y];
   if(x&1)
   {
      pxl>>=4;
   }
   return pxl&0x0F;
}

void set_bw()
{
   gpu_clut_set(0,0);
   gpu_clut_set(1,0xFFFF);
   gpu_clut_set(2,0x2222);
   gpu_clut_set(3,0x3333);
   gpu_clut_set(4,0);
   gpu_clut_set(5,0);
   gpu_clut_set(6,0);
   gpu_clut_set(7,0);
   gpu_clut_set(8,0);
   gpu_clut_set(9,0);
   gpu_clut_set(10,0);
   gpu_clut_set(11,0);
   gpu_clut_set(12,0);
   gpu_clut_set(13,0);
   gpu_clut_set(14,0xEEEE);
   gpu_clut_set(15,0xFFFF);
   //gpu_clut_set(1,0xFFFF);
}

void gfx_init()
{
   //TODO: figure out how clear vram with numbers less than 2^16
   uint32_t i;
   cursor_x = 16;
   cursor_y = 16;
   gpu_init();
   gpu_config_clut();
   gpu_vsync();
   drawbuf = &GFXDisplayBuffer[0];
   backbuf = &GFXDisplayBuffer[38400];
   for(i=0;i<38400;i++)
   {
      drawbuf[i]=0;
      backbuf[i]=0;
   }
   
   gfx_clear_screen();
   gfx_flip();
   gfx_clear_screen();
   gfx_flip();
   gfx_clear_screen();
}
