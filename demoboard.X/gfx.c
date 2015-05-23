#if 0
#include <xc.h>
#include <stdint.h>
#define  FCY    16000000UL    // Instruction cycle frequency, Hz
#include <libpic30.h>


#define CLOCKDIV 69
#define HOR_RES 80UL
#define VER_RES 480UL
#define HOR_FRONT_PORCH 32
#define HOR_PULSE_WIDTH 8
#define HOR_BACK_PORCH  32
#define VER_FRONT_PORCH 10
#define VER_PULSE_WIDTH 5
#define VER_BACK_PORCH  10
#define BPP 8
#define VENST_FUDGE 0
#define HENST_FUDGE 0
#define VSPOL 0 /* sync polarities */
#define HSPOL 0

#define PIX_W 1

uint8_t PIX_H = VER_RES/HOR_RES;
uint16_t frames = 0;
 
#define CHR_FGCOLOR	     0x5000
#define CHR_BGCOLOR	     0x5100
#define CHR_FONTBASE	    0x5200
#define CHR_PRINTCHAR	   0x5300
#define CHR_TXTAREASTART	0x5800
#define CHR_TXTAREAEND	  0x5900
#define CHR_PRINTPOS	    0x5A00
#define RCC_SRCADDR	     0x6200
#define RCC_DESTADDR	    0x6300
#define RCC_RECTSIZE	    0x6400
#define RCC_COLOR	       0x6600
#define RCC_STARTCOPY	   0x6700
#define IPU_SRCADDR	     0x7100
#define IPU_DESTADDR	    0x7200
#define IPU_DECOMPRESS	  0x7400
 
#define GFX_BUFFER_SIZE (HOR_RES * VER_RES / (8/BPP))
//__eds__ uint8_t GFXDisplayBuffer[2][GFX_BUFFER_SIZE] __attribute__((eds, section("DISPLAY"), address(0x1000)));
//__eds__ uint8_t GFXDisplayBuffer[GFX_BUFFER_SIZE] __attribute__((section("DISPLAY"),space(eds)));


void config_graphics(void) {
	_G1CLKSEL = 1;
	_GCLKDIV = CLOCKDIV;
 
	G1DPADRL = (unsigned long)(GFXDisplayBuffer) & 0xFFFF;
	G1DPADRH = (unsigned long)(GFXDisplayBuffer) >>16 & 0xFF;
	G1W1ADRL = (unsigned long)(GFXDisplayBuffer) & 0xFFFF;
	G1W1ADRH = (unsigned long)(GFXDisplayBuffer) >>16 & 0xFF;
	G1W2ADRL = (unsigned long)(GFXDisplayBuffer) & 0xFFFF;
	G1W2ADRH = (unsigned long)(GFXDisplayBuffer) >>16 & 0xFF;
 
	_GDBEN = 0xFFFF;
 
	// Using PIC24F manual section 43 page 37-38
	_DPMODE = 1;      /* TFT */
	_GDBEN = 0xFFFF;
	_DPW = _PUW = HOR_RES; // Work area and FB size so GPU works
	_DPH = _PUH = VER_RES;
	_DPWT = HOR_FRONT_PORCH + HOR_PULSE_WIDTH + HOR_BACK_PORCH + HOR_RES;
	_DPHT = (VER_FRONT_PORCH + VER_PULSE_WIDTH + VER_BACK_PORCH)*2 + VER_RES;
	_DPCLKPOL = 0;
	_DPENOE = 0;
	_DPENPOL = 0;
	_DPVSOE = 1;
	_DPHSOE = 1;
	_DPVSPOL = VSPOL;
	_DPHSPOL = HSPOL;
	_ACTLINE = _VENST = VER_FRONT_PORCH + VER_PULSE_WIDTH + VER_BACK_PORCH - VENST_FUDGE;
	_ACTPIX = _HENST = HOR_FRONT_PORCH + HOR_PULSE_WIDTH + HOR_BACK_PORCH - HENST_FUDGE;
	_VSST = VER_FRONT_PORCH;
	_HSST = HOR_FRONT_PORCH;
	_VSLEN = VER_PULSE_WIDTH;
	_HSLEN = HOR_PULSE_WIDTH;
	_DPPWROE = 0;
	_DPPINOE = 1;
	_DPPOWER = 1;
	int logc=0;
	while (BPP>>logc > 1) { logc++; }
	_DPBPP = _PUBPP = logc;
	_G1EN = 1;
	__delay_ms(1);
}
#endif
