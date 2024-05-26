#include <stdio.h>

#include "basic_functions.h"

#include "gfx.h"
#include "uart.h"
#include "demo.h"

char line[80];
uint8_t cursor = 0;
uint8_t editor_state = 0;

extern keyword keywords[];

void editor_list()
{
    int i;
    __eds__ program_line *line;
    uint16_t pc = 0;
    line = program_get_line(pc);
    while(line)
    {
        pc = line->lineno + 1;
        if(line->cmd >= 128)
        {
            fprintf(stdout,"%d %s ",line->lineno,keywords[line->cmd-128].name);
        }
        else
        {
            fprintf(stdout,"%d ",line->lineno);
        }
        for(i=0;i<80;i++)
        {
            if(line->args[i] == 0)
            {
                break;
            }
            fputc(line->args[i],stdout);
        }
        fputc('\n',stdout);
        line = program_get_line(pc);
    }
}

int editor_run()
{
    uint8_t in_ch;
    switch(editor_state)
    {
        case 0:
            for(cursor=79;cursor;cursor--)
            {
                line[cursor]=0;
            }
            line[cursor]=0;
            putc('>',stdout);
            putc('>',stderr);
            editor_state = 1;
            break;
        case 1:
            if(uart_rx_available())
            {
                in_ch = uart_rx();
                demo_disable();
            }
            else if(demo_has_byte())
            {
                in_ch = demo_get_byte();
            }
            else
            {
                break;
            }
            if(in_ch == '\r')
            {
                in_ch = '\n';
            }
            if(in_ch >= ' ' && in_ch <= '~')
            {
                if(cursor<80)
                {
                    line[cursor++]=in_ch;
                }
            }
            if(in_ch == '\b')
            {
                line[--cursor]=0;
            }
            if(in_ch == '\n')
            {
                editor_state = 2;
            }
            //screen_putch(in_ch);
            if(cursor < 80 || in_ch == '\n' || in_ch == '\b')
            {
                putc(in_ch,stdout);
                putc(in_ch,stderr);
            }
            break;
        case 2:
            if(program_is_code(line))
            {
                program_add_line(line);
            }
            else
            {
                line[79] = 0;
                parser_parse_text(line);
            }
            editor_state = 0;
            break;
    }
    return 1;
}