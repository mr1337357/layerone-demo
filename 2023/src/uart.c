#include <xc.h>
#define FCY 16000000UL // Instruction cycle frequency, Hz
#include <libpic30.h>

//#include "p24FJ256DA206.h"

#define BRATE 9600

static uint16_t calc_brg(uint32_t brate)
{
    uint32_t brg;
    brg = FCY;
    brg /= 16;
    brg /= brate;
    brg-=1;
    return brg;
}

void uart_init()
{
    uint16_t brg;
    ANSB = 0;
    TRISB |= 0x0080;
    RPINR18bits.U1RXR = 7;
    //RPINR18 = 0x0007; //UART1RX = PIN7
    RPOR3bits.RP6R = 3;
    //RPOR3 = 0x0003; //PIN6 = UART1TX
    brg = calc_brg(BRATE);
    //U1MODE = 0x0008;
    U1BRG = brg;
    U1MODE |= 0x8000;
    U1STA = 0x0400;
}

void uart_tx(uint8_t c)
{
    while(!U1STAbits.TRMT);
    U1TXREG = c;
}

uint8_t uart_rx()
{
    while(!U1STAbits.URXDA);
    return U1RXREG;
}

uint8_t uart_rx_available()
{
    U1STAbits.FERR = 0;
    U1STAbits.OERR = 0;
    U1STAbits.PERR = 0;
    return U1STAbits.URXDA;
}

void uart_puts(uint8_t *msg)
{
    while(*msg)
    {
        uart_tx(*msg);
        msg++;
    }
}