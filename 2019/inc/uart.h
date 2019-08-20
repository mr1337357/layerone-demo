#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>

void uart_init();

void uart_tx(uint8_t c);

void uart_puts(char *msg);

uint8_t uart_rx();

#endif //_UART_H_