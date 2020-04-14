#include "audio.h"
#include <xc.h>

#define STILL_ALIVE
#include "songs.h"

int16_t sine[] =
{
    0x0000, 0x0006, 0x000C, 0x0012, 0x0018, 0x001E, 0x0024, 0x002A,
    0x0030, 0x0036, 0x003B, 0x0041, 0x0046, 0x004B, 0x0050, 0x0055,
    0x0059, 0x005E, 0x0062, 0x0066, 0x0069, 0x006C, 0x0070, 0x0072,
    0x0075, 0x0077, 0x0079, 0x007B, 0x007C, 0x007D, 0x007E, 0x007E,
    0x007F, 0x007E, 0x007E, 0x007D, 0x007C, 0x007B, 0x0079, 0x0077,
    0x0075, 0x0072, 0x0070, 0x006C, 0x0069, 0x0066, 0x0062, 0x005E,
    0x0059, 0x0055, 0x0050, 0x004B, 0x0046, 0x0041, 0x003B, 0x0036,
    0x0030, 0x002A, 0x0024, 0x001E, 0x0018, 0x0012, 0x000C, 0x0006,
    0x0000, 0xFFFA, 0xFFF4, 0xFFEE, 0xFFE8, 0xFFE2, 0xFFDC, 0xFFD6,
    0xFFD0, 0xFFCA, 0xFFC5, 0xFFBF, 0xFFBA, 0xFFB5, 0xFFB0, 0xFFAB,
    0xFFA7, 0xFFA2, 0xFF9E, 0xFF9A, 0xFF97, 0xFF94, 0xFF90, 0xFF8E,
    0xFF8B, 0xFF89, 0xFF87, 0xFF85, 0xFF84, 0xFF83, 0xFF82, 0xFF82,
    0xFF81, 0xFF82, 0xFF82, 0xFF83, 0xFF84, 0xFF85, 0xFF87, 0xFF89,
    0xFF8B, 0xFF8E, 0xFF90, 0xFF94, 0xFF97, 0xFF9A, 0xFF9E, 0xFFA2,
    0xFFA7, 0xFFAB, 0xFFB0, 0xFFB5, 0xFFBA, 0xFFBF, 0xFFC5, 0xFFCA,
    0xFFD0, 0xFFD6, 0xFFDC, 0xFFE2, 0xFFE8, 0xFFEE, 0xFFF4, 0xFFFA,
};

int16_t square[] = 
{
    0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 
    0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 
    0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 
    0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 
    0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 
    0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 
    0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 
    0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x007F, 0x0000, 
    0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 
    0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 
    0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 
    0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 
    0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 
    0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 
    0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 
    0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0xFF81, 0x0000, 
};

int16_t triangle[] = 
{
    0x80,0x8F,0x9F,0xaf,0xbf,0xcf,0xdf,0xef,
    0xff,0xef,0xdf,0xcf,0xbf,0xaf,0x9f,0x8f,
    0x80,0x70,0x60,0x50,0x40,0x30,0x20,0x10,
    0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,
};

void audio_setup() {
    PR1 = 256;
    _T1IP = 5;	// set interrupt priority
    _TON  = 1;	// turn on the timer
    _T1IF = 0;	// reset interrupt flag
    _T1IE = 1;	// turn on the timer1 interrupt
}

//CP: Channel Phase
//CF: Channel Frequency
static unsigned int notendx=-1;

static uint16_t cp1=0;
static unsigned short cp2=0;
static unsigned short cp3=0;
static unsigned short cp4=0;

static int16_t ca1=64;
static int16_t ca2=16;
static int16_t ca3=16;
static int16_t ca4=64;

static unsigned short cf1=0;
static unsigned short cf2=0;
static unsigned short cf3=0;
static unsigned short cf4=0;
static unsigned short filt;

static unsigned short samplendx=0;

void __attribute__((__interrupt__)) _T1Interrupt(void);
void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void)
{
    int16_t sample=0;
    sample = sine[cp1>>9]*ca1;
    sample+= square[cp2>>9]*ca2;
    sample+= square[cp3>>9]*ca3;
    sample+= sine[(cp4>>9)&~3]*ca4;
    //sample>>=2;
    //sample<<=6;
    sample^=0x8000;
    PORTB=(sample);
    cp1+=cf1;
    cp2+=cf2;
    cp3+=cf3;
    cp4+=cf4;
    samplendx++;
    if(samplendx==16384) {
        samplendx=0;
        notendx++;
        if(notendx==(sizeof(c1f)/sizeof(c1f[0]))) {
            _TON  = 0;
            notendx=0;
        }
        
        cf1=c1f[notendx];
        cf2=c2f[notendx];
        cf3=c3f[notendx];
        cf4=c4f[notendx];
        filt=fltr[notendx];
    }
    _T1IF = 0;
}
