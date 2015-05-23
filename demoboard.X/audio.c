#include "audio.h"
#include "soundfx.h"
#include <xc.h>

#define STILL_ALIVE
#include "songs.h"

void audio_setup() {
    PR1 = 256;
    _T1IP = 5;	// set interrupt priority
    _TON  = 1;	// turn on the timer
    _T1IF = 0;	// reset interrupt flag
    _T1IE = 1;	// turn on the timer1 interrupt
}


static unsigned int notendx=-1;
static unsigned short channdx1=0;
static unsigned short channdx2=0;
static unsigned short channdx3=0;
static unsigned short channdx4=0;
static unsigned short cf1=0;
static unsigned short ca1=0;
static unsigned short cf2=0;
static unsigned short ca2=0;
static unsigned short cf3=0;
static unsigned short ca3=0;
static unsigned short cf4=0;
static unsigned short ca4=0;
static unsigned short filt;

static unsigned short samplendx=0;

void __attribute__((__interrupt__)) _T1Interrupt(void);
void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void)
{
    unsigned short sample=0;
    unsigned short sample2;
    if(cf1>channdx1<<1) {
        sample=ca1;
    }
    if(filt&1&&samplendx>14000) {
        sample=0;
    }
    if(filt&2&&samplendx&1024) {
        sample>>=1;
    }
    if(cf2>channdx2<<1) {
        sample2=ca2;
    } else {
        sample2=0;
    }
    if(filt&4&&samplendx>14000) {
        sample2=0;
    }
    if(filt&8&&samplendx&1024) {
        sample2>>=1;
    }
    sample+=sample2;
    if(cf3>channdx3<<1) {
        sample2=ca3;
    } else {
        sample2=0;
    }
    if(filt&16&&samplendx>14000) {
        sample2=0;
    }
    if(filt&32&&samplendx&1024) {
        sample2>>=1;
    }
    sample+=sample2;
    if(cf4>channdx4<<1) {
        sample2=ca4;
    } else {
        sample2=0;
    }
    if(filt&64&&samplendx>14000) {
        sample2=0;
    }
    if(filt&128&&samplendx&1024) {
        sample2>>=1;
    }
    sample+=sample2;
    PORTB=(sample<<8);
    channdx1++;
    if(channdx1>cf1) {
        channdx1=0;
    }
    channdx2++;
    if(channdx2>cf2) {
        channdx2=0;
    }
    channdx3++;
    if(channdx3>cf3) {
        channdx3=0;
    }
    channdx4++;
    if(channdx4>cf4) {
        channdx4=0;
    }
    samplendx++;
    if(samplendx==16384) {
        samplendx=0;
        notendx++;
        if(notendx==(sizeof(c1f)/sizeof(c1f[0]))) {
            notendx=0;
        }
        
        cf1=c1f[notendx];
        ca1=c1a[notendx];
        cf2=c2f[notendx];
        ca2=c2a[notendx];
        cf3=c3f[notendx];
        ca3=c3a[notendx];
        cf4=c4f[notendx];
        ca4=c4a[notendx];
        filt=fltr[notendx];
    }
    _T1IF = 0;
}
