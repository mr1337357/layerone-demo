#include "audio.h"
#include "soundfx.h"
#include <xc.h>

#define STILL_ALIVE
#include "songs.h"

unsigned short sin[] =
{
    0x80,0x98,0xb0,0xc6,0xda,0xea,0xf5,0xfd,
    0xff,0xfd,0xf5,0xea,0xda,0xc6,0xb0,0x98,
    0x80,0x67,0x4f,0x39,0x25,0x15,0x0a,0x02,
    0x00,0x02,0x0a,0x15,0x25,0x39,0x4f,0x67,
};

unsigned short triangle[] = 
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
static unsigned short cp1=0;
static unsigned short cp2=0;
static unsigned short cp3=0;
static unsigned short cp4=0;
static unsigned short cf1=0;
static unsigned short cf2=0;
static unsigned short cf3=0;
static unsigned short cf4=0;
static unsigned short filt;

static unsigned short samplendx=0;

void __attribute__((__interrupt__)) _T1Interrupt(void);
void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void)
{
    unsigned short sample=0;
    sample = sin[cp1>>11];
    sample+= sin[cp2>>11];
    sample+= sin[cp3>>11];
    sample+= triangle[cp4>>11];
    //sample>>=2;
    PORTB=(sample<<6);
    cp1+=cf1;
    cp2+=cf2;
    cp3+=cf3;
    cp4+=cf4;
    samplendx++;
    if(samplendx==16384) {
        samplendx=0;
        notendx++;
        if(notendx==(sizeof(c1f)/sizeof(c1f[0]))) {
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
