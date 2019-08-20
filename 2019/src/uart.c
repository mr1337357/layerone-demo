#include <xc.h>
#define FCY 16000000UL // Instruction cycle frequency, Hz
#include <libpic30.h>

#include "uart.h"

#define BRATE 9600

uint8_t rxbuf[16];
uint8_t rxwptr;
uint8_t rxrptr;
uint8_t rxlen;

uint8_t txbuf[16];
uint8_t txwptr;
uint8_t txrptr;
uint8_t txlen;

void __attribute__((interrupt, auto_psv))_U1RXInterrupt(void)
{
    rxbuf[rxwptr++] = U1RXREG;
    rxwptr&=0x0F;
    rxlen++;
    IFS0&=~0x0800;
}

void __attribute__((interrupt, auto_psv))_U1TXInterrupt(void)
{
    while(txlen)
    {
        U1TXREG=txbuf[txrptr++];
        txrptr&=0x0F;
        txlen--;
        if(U1STA&0x0200)
        {
            IFS0&=~0x1000;
            return;
        }
    }
    
    IEC0&=~0x1000;
    //IFS0&=~0x1000;
}

static uint16_t calc_brg(uint32_t brate)
{
    uint32_t brg;
    brg = FCY;
    brg /= 4;
    brg /= brate;
    brg-=1;
    return brg;
}

void uart_init()
{
    uint16_t brg;
    TRISB |= 0x0080;
    RPINR18 = 0x0007; //UART1RX = PIN7
    RPOR3 = 0x0003; //PIN6 = UART1TX
    brg = calc_brg(BRATE);
    U1MODE |= 0x0008;
    U1BRG = brg;
    U1MODE |= 0x8000;
    U1STA = 0x0400;
    txwptr = 0;
    txrptr = 0;
    txlen = 0;
    rxwptr = 0;
    rxrptr = 0;
    rxlen = 0;
    IEC0|=0x0800;
    //U1IE=1;
}

void uart_tx(uint8_t c)
{
    txbuf[txwptr++]=c;
    txwptr&=0x0F;
    txlen++;
    IEC0|=0x1000;
}

void uart_puts(char *msg)
{
    while(*msg)
    {
        while(txlen>14)
        {
            IEC0|=0x1000;
        }
        txbuf[txwptr++]=*msg;
        txlen++;
        txwptr&=0x0F;
        msg++;
    }
    IEC0|=0x1000;
}

uint8_t uart_rx()
{
    uint8_t rx;
    while(!rxlen);
    rx = rxbuf[rxrptr++];
    rxrptr &= 0x0F;
    rxlen--;
    return rx;
}