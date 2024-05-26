#include <xc.h>
#define FCY 16000000UL // Instruction cycle frequency, Hz
#include <libpic30.h>

#include "gfx.h"
#include "gpu.h"

uint16_t random()
{
   static uint16_t seed = 0;
   uint16_t rv;
   seed<<=1;
   seed|=((seed>>9)+(seed>>5)+1)&1;
   rv = seed;
   return rv;
}

void fire_init()
{
   int i;
   //gfx_singlebuffer();
   gpu_clut_set(15,0xFFFF);
   gpu_clut_set(14,0xFFF8);
   gpu_clut_set(13,0xFFF0);
   gpu_clut_set(12,0xFFE0);
   gpu_clut_set(11,0xFF00);
   gpu_clut_set(10,0xFE00);
   gpu_clut_set(9,0xFC00);
   gpu_clut_set(8,0x0);
   gpu_clut_set(7,0x0);
   gpu_clut_set(6,0x0);
   gpu_clut_set(5,0x0);
   gpu_clut_set(4,0x0);
   gpu_clut_set(3,0x0);
   gpu_clut_set(2,0x0);
//   gpu_clut_set(1,0x0);
//   gpu_clut_set(0,0x0);
   
   //row of white
   for(i=1;i<318;i++)
   {
      gfx_drawpixel(i,239,15);
   }
   gfx_flip();
   for(i=1;i<318;i++)
   {
      gfx_drawpixel(i,239,15);
   }
}
void fire_step()
{
   uint16_t color;
   int i,j;
   for(j=0;j<20;j++)
   {
      random()&&random();
      for(i=1;i<318;i++)
      {
         color = gfx_getpixel(i,j+220);

         //if(random()&1)
         //{
         //   color -=1;
         //}
         if(random()&1)
         {  
            color -=1;
         }
         if(color>15)
         {
            color = 0;
         }
         gfx_drawpixel(i,j+219,color);
      }
   }

   //gpu_vsync();
}
