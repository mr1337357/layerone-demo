#include <stdint.h>
#include "render.h"
#include "gfx.h"
#include "uart.h"

#define xstr(s) str(s)
#define str(s) #s

//lets do fixed point math ranging from -2 to 2
// :)

//-2     is 0x8000
//-1     is 0xC000 ??
// 1.975 is 0x7FFF
// 1     is 0x4000
// 1/32  is 0x0400

#define SPRITESIZE 32
#define SPRITESTEP 0x0400
#define NEGONE 0xC000 //negative one. I'm too lazy for good names
#define ONE 0x4000

void project(vector *loc,int16_t *x,int16_t *y)
{
   int32_t temp;

   temp = *x;
   temp += loc->x;
   temp *= 0x4000;
   temp /= loc->z;
   *x=temp;
   temp = *y;
   temp += loc->y;
   temp *= 0x4000;
   temp /= loc->z;
   *y=temp;
}

void blit_25d(uint8_t *sprite,vector *loc)
{
   //let's fix the resolution at 32x32 for now
   //iterate over sprite, generating coordinates
   
   int16_t x;
   int16_t y;
   int16_t newx;
   int16_t newy;
   uint16_t screenx;
   uint16_t screeny;
   uint16_t c;
   for(y=NEGONE;y<ONE;y+=SPRITESTEP)
   {
      for(x=NEGONE;x<ONE;x+=SPRITESTEP)
      {
         c = *sprite;
         c &= 0x0F;
         if(c)
         {
            newx=x;
            newy=y;
            project(loc,&newx,&newy);
            screenx=160;
            screeny=120;
            newx/=SPRITESTEP;
            newy/=SPRITESTEP;
            screenx+=newx;
            screeny+=newy;
            gfx_drawpixel(screenx,screeny,c);
         }
         x+=SPRITESTEP;
         c = *sprite;
         c >>= 4;
         if(c)
         {
            newx=x;
            newy=y;
            project(loc,&newx,&newy);
            screenx=160;
            screeny=120;
            newx/=SPRITESTEP;
            newy/=SPRITESTEP;
            screenx+=newx;
            screeny+=newy;
            gfx_drawpixel(screenx,screeny,c);
         }
         sprite++;
      }
   }
}
