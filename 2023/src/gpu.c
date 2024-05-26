#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <string.h>
#include <math.h>
#include "fonts.h"
#include "gpu.h"
//#include "alu.h"

#define  FCY    16000000UL    // Instruction cycle frequency, Hz
#include <libpic30.h>

#define CLOCK_DIV 58
#define HRES 320
#define VRES 240
#define HFP 32
#define HPW 16
#define HBP 32
#define VFP 5
#define VPW 3
#define VBP 5

volatile static int vsync = 0;

__eds__ uint8_t GFXDisplayBuffer[76800] __attribute__((section("DISPLAY"),space(eds)));

void __attribute__((interrupt, auto_psv))_GFX1Interrupt(void) 
{
	
	if(_VMRGNIF)            // Vertical Sync Flag
    {
		vsync = 0;
		_VMRGNIF = 0;
	} 
	_GFX1IF = 0;
}

void gpu_vsync()
{
   vsync=1;
   while(vsync);
}

void gpu_init(void)
{
    //interrupt setup
    //vsync
    _VMRGNIF = 0;
    _VMRGNIE = 1;
    //hsync
    _HMRGNIF = 0;
    _HMRGNIE = 0;
    //global
    _GFX1IE = 1;
    
    _G1CLKSEL = 1;
    _GCLKDIV = CLOCK_DIV;

    // Display buffer:
    G1DPADRL = (uint32_t)(&GFXDisplayBuffer[0]) & 0xFFFF;
    G1DPADRH = (uint32_t)(&GFXDisplayBuffer[0]) >>16 & 0xFF;

    // Work area 1
    G1W1ADRL = (uint32_t)(&GFXDisplayBuffer[0]) & 0xFFFF;
    G1W1ADRH = (uint32_t)(&GFXDisplayBuffer[0]) >>16 & 0xFF;

    // Work area 2
    G1W2ADRL = (uint32_t)(&GFXDisplayBuffer[0]) & 0xFFFF;
    G1W2ADRH = (uint32_t)(&GFXDisplayBuffer[0]) >>16 & 0xFF;
    
    // Horizontal and Vertical Resolution
    G1PUW = HRES;
    G1PUH = VRES;

    // Using PIC24F manual section 43 page 37-38
    _DPMODE = 1;            // TFT
    _GDBEN = 0xFFFF;
    _DPW = _PUW = HRES; // Work area and FB size so GPU works
    _DPH = _PUH = VRES;
    _DPWT = HFP + HPW + HBP + HRES;

    // _DPHT may need to be adjusted for vertical centering
    _DPHT = (VFP + VPW + VBP)*2 + VRES;
    _DPCLKPOL = 0;
    _DPENOE = 0;
    _DPENPOL = 0;
    _DPVSOE = 1;          // use VSYNC
    _DPHSOE = 1;          // use HSYNC
    _DPVSPOL = VSPOL;     // VSYNC negative polarity (if VSPOL = 0)
    _DPHSPOL = HSPOL;     // HSYNC negative polarity (if HSPOL = 0)

    // _ACTLINE may need to be adjusted for vertical centering
    _ACTLINE = _VENST = VFP + VPW + VBP - VENST_FUDGE;
    _ACTPIX = _HENST = HFP + HPW + HBP - HENST_FUDGE;
    _VSST = VFP;
    _HSST = HFP;
    _VSLEN = VPW;
    _HSLEN = HPW;
    _DPPWROE = 0;
    _DPPINOE = 1;
    _DPPOWER = 1;

    //int logc=0;
    //while (gfx.bpp>>logc > 1) { logc++; }
    _DPBPP = _PUBPP = 2;//logc;

    _VMRGNIE = 1;
    _HMRGNIE = 1;

    _G1EN = 1;
    __delay_ms(1);
}

void gpu_flush()
{
   while(!_CMDMPT);
   while(_IPUBUSY);
   while(_RCCBUSY);
   while(_CHRBUSY);
}

void gpu_set_fb(__eds__ uint8_t *buf) 
{
    G1DPADRL = (uint32_t)(buf);
    G1DPADRH = (uint32_t)(buf);
}

void gpu_flip_fb() 
{
    static uint8_t fb_index = 1;

    while((!_CMDMPT) | _IPUBUSY | _RCCBUSY | _CHRBUSY) continue; // Wait for IPU, RCC, and CHR GPUs to finish drawing
    
    vsync = 1;

    while(vsync) continue;                                       // Wait for Vsync to clear

     if(fb_index)
     {
         gpu_set_fb(&GFXDisplayBuffer[0]);
         rcc_set_fb_dest(&GFXDisplayBuffer[38400]);
     }
     else
     {
         gpu_set_fb(&GFXDisplayBuffer[38400]);
         rcc_set_fb_dest(&GFXDisplayBuffer[0]);
     }
     
     fb_index = !fb_index;
}

void gpu_clear_fb(void) 
{
    rcc_color(0);
    rcc_rec(0, 0, 320, 240);
}


void gpu_config_clut() 
{
    _CLUTEN = 1; 
}

void gpu_clut_set(uint8_t index, uint16_t color) 
{
    _CLUTADR = index;
    _CLUTRWEN = 1;
    G1CLUTWR = color;
    while(_CLUTBUSY) continue;
    _CLUTRWEN = 0;
}

void chr_init(void) 
{
    while(_CMDFUL) continue;
    G1CMDL = 0xFFFF;
    G1CMDH = CHR_FGCOLOR;
    Nop();
 
    while(_CMDFUL) continue;
    G1CMDL = 0;
    G1CMDH = CHR_BGCOLOR;
    Nop();
 
    while(_CMDFUL) continue;
    G1CMDL = (uint32_t)(&FontStart[0]) & 0xFFFF;
    G1CMDH = CHR_FONTBASE | (((uint32_t)(&FontStart[0])>>16) & 0xFF);
    Nop();
 
    while(_CMDFUL) continue;
    G1CMDL = 0;
    G1CMDH = CHR_TXTAREASTART;
    Nop();
 
    while(_CMDFUL) continue;
    G1CMDL = ((HRES & 0xF) << 12) | VRES;
    G1CMDH = CHR_TXTAREAEND | (VRES >> 4);
    Nop();
}

void chr_print(char *c, uint16_t x, uint16_t y, uint8_t transparent) 
{
    // Credits: Jamis
    int maxCharHeight = ((int)VRES)-21;

    if (y > maxCharHeight) 
    {
        y = maxCharHeight;
    }

    while(_CMDFUL) continue;
    G1CMDL = x<<12 | y;
    G1CMDH = CHR_PRINTPOS | (x>>4);
    Nop();

    while(*c != NULL) 
    {
        while(_CMDFUL) continue;
        G1CMDL = *c;
        if(transparent == 0)
        {
            G1CMDH = CHR_PRINTCHAR;
        }
        else
        {
            G1CMDH = CHR_PRINTCHARTRANS; // transparent
        }
        Nop();

        c++;
    }
}

void chr_fg_color(unsigned int color) 
{
    G1CMDL = color;
    G1CMDH = CHR_FGCOLOR;
}
 
void chr_bg_color(unsigned int color) 
{
    G1CMDL = color;
    G1CMDH = CHR_BGCOLOR;
}

void rcc_set_fb_dest(__eds__ uint8_t *buf) 
{
    while(!_CMDMPT) continue;   // Wait for GPU to finish drawing
    //G1W1ADRL = (uint32_t)(buf);
    //G1W1ADRH = (uint32_t)(buf);
    G1W2ADRL = (uint32_t)(buf);
    G1W2ADRH = (uint32_t)(buf);
}

void rcc_set_fb_src(__eds__ uint8_t *buf)
{
    while(!_CMDMPT) continue;   // Wait for GPU to finish drawing
    G1W1ADRL = (uint32_t)(buf);
    G1W1ADRH = (uint32_t)(buf);
}

void rcc_color(unsigned int color) 
{
	G1CMDL = color;
	G1CMDH = RCC_COLOR;
}

void rcc_rec(uint16_t x, uint16_t y, uint16_t w, uint16_t h) 
{
	// destination
	while(_CMDFUL) continue;
	G1CMDL = x + (y * HRES);
	G1CMDH = RCC_DESTADDR | (((x + (y * (uint32_t)HRES))>>16) & 0xFF);
	Nop();
 
	// size
	while(_CMDFUL) continue;
	G1CMDL = (w<<12) | h;
	G1CMDH = RCC_RECTSIZE | (w>>4);
	Nop();
 
	// go!
	while(_CMDFUL) continue;
	G1CMDL = RCC_ROP_COPY;
	G1CMDH = RCC_STARTCOPY;
	Nop();
}

void rcc_blit(uint32_t sprite, uint16_t x, uint16_t y, uint16_t w, uint16_t h) 
{
   if(G1CON1bits.GCMDCNT > 8)
   {
       
   }
   //transparent color
   while(_CMDFUL) continue;
   G1CMDL = 0;
   G1CMDH = RCC_COLOR;
   
   // source
   while(_CMDFUL) continue;
   G1CMDL = sprite;
   G1CMDH = RCC_SRCADDR | ((sprite>>16)&0xFF);
   
	// destination
	while(_CMDFUL) continue;
	G1CMDL = x + (y * HRES);
	G1CMDH = RCC_DESTADDR | (((x + (y * (uint32_t)HRES))>>16) & 0xFF);
	Nop();
 
	// size
	while(_CMDFUL) continue;
	G1CMDL = (w<<12) | h;
	G1CMDH = RCC_RECTSIZE | (w>>4);
	Nop();
 
	// go!
	while(_CMDFUL) continue;
	G1CMDL = RCC_ROP_COPY|RCC_OPER_COPY|2;
	G1CMDH = RCC_STARTCOPY;
	Nop();
}

void rcc_scroll()
{
    rcc_set_fb_dest(&GFXDisplayBuffer[0]);
    rcc_set_fb_src(&GFXDisplayBuffer[0]);
    
    while(_CMDFUL) continue;
    G1CMDL = 0;
    G1CMDH = RCC_COLOR;
    while(_CMDFUL) continue;
    G1CMDL = 2560;
    G1CMDH = RCC_SRCADDR | ((2560L>>16)&0xFF);
    while(_CMDFUL) continue;
    G1CMDL = 0;
	G1CMDH = RCC_DESTADDR | ((0L>>16)&0xFF);
	Nop();
    while(_CMDFUL) continue;
	G1CMDL = (320<<12) | 232;
	G1CMDH = RCC_RECTSIZE | (320>>4);
	Nop();
    while(_CMDFUL) continue;
	G1CMDL = RCC_ROP_COPY|RCC_OPER_COPY|0;
	G1CMDH = RCC_STARTCOPY;
	Nop();
    //restore RCC
    rcc_set_fb_dest(&GFXDisplayBuffer[0]);
    rcc_set_fb_src(&GFXDisplayBuffer[38400]);
}

void rcc_pixel(unsigned long ax, unsigned long ay) 
{
	ax += ay * HRES;
	G1CMDL = ax;
	G1CMDH = RCC_DESTADDR | ((ax>>16) & 0xFF);

	G1CMDL = 0x1000 | 1;
	G1CMDH = RCC_RECTSIZE;

	while(_CMDFUL) continue;
	G1CMDL = RCC_ROP_COPY;
	G1CMDH = RCC_STARTCOPY;
	Nop();

}
