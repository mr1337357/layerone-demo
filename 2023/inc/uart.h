#include <stdint.h>
void uart_init();

void uart_tx(uint8_t c);

void uart_puts(uint8_t *msg);

void uart_put_hex(uint16_t value);

uint8_t uart_rx_available();
 
uint8_t uart_rx();