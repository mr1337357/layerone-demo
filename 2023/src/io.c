#include "gfx.h"
#include "uart.h"
int write(int handle, void *buffer, unsigned int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if(handle == 1)
        {
            screen_putch(*(char*) buffer++);
        }
        if(handle == 2)
        {
            uart_tx(*(char*) buffer++);
        }
    }
    return (len);
}