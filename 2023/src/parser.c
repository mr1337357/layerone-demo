#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "basic_functions.h"

#include "gfx.h"

keyword keywords[] = 
{
    {"REM",0},
    {"LET",interpreter_let_handler},
    {"IF",interpreter_if_handler},
    {"GOTO",interpreter_goto_handler},
    {"LIST",editor_list},
    {"VARS",variable_dump},
    {"PRINT",interpreter_print_handler},
    {"RUN",interpreter_run_handler},
    {"CLEAR",gfx_clear_screen},
    {"DOT",draw_dot},
    {"GOSUB",interpreter_gosub_handler},
    {"RET",interpreter_ret_handler},
    {"PRINTS",interpreter_prints_handler},
    {"DUMP",program_dump},
    {"COLOR",color_handler},
    {"DEBUG",interpreter_debug_handler},
    {"BREAKPOINT",interpreter_breakpoint_handler},
    {"RESUME",interpreter_run},
    {"CURSOR",0},
    {"DELAY",0},
};

uint8_t parser_find_keyword(char *cmd,char **consume)
{
    uint8_t i;
    uint8_t j;
    for(i=0;i<sizeof(keywords)/sizeof(keywords[0]);i++)
    {
        if(cmd[0] == keywords[i].name[0])
        {
            for(j=0;j<strlen(keywords[i].name);j++)
            {
                if(cmd[j] != keywords[i].name[j])
                {
                    break;
                }
            }
            if(j!=strlen(keywords[i].name) || (cmd[j] != 0 && cmd[j] != ' '))
            {
                continue;
            }
            if(consume)
            {
                *consume+=strlen(keywords[i].name);
            }
            return i+128;
        }
    }
    return 0;
}

/* returns token if token, returns null if no token */
/* moves argument to first byte after token */
__eds__ uint8_t *parser_get_token(__eds__ uint8_t **text)
{
    __eds__ uint8_t *tp = *text;
    __eds__ uint8_t *rv = 0;
    while(*tp == ' ')
    {
        tp++;
    }
    
    if(*tp == 0)
    {
        return 0;
    }
    rv = tp;
    while(*tp != 0 && *tp != ' ')
    {
        tp++;
    }
    *text = tp;
    return rv;
}

/*TODO MOVE TO DIFFERENT FILE*/
void parser_handle_list(char *args)
{
    int i;
    __eds__ program_line *line;
    uint16_t pc = 0;
    while(pc < 65536)
    {
        line = program_get_line(pc);
        if(!line)
        {
            break;
        }
        if(line->lineno < pc)
        {
            break;
        }
        pc = line->lineno + 1;
        if(line->cmd >= 128)
        {
            printf("%d %s ",line->lineno,keywords[line->cmd-128].name);
        }
        else
        {
            printf("%d ",line->lineno);
        }
        for(i=0;line->args[i]!=0;i++)
        {
            printf("%c",line->args[i]);
        }
        printf("\n");
    }
}

void parser_parse_text(char *text)
{
    uint8_t index;
    union
    {
        program_line line;
        uint8_t text[80];
    } lt;
    lt.line.cmd = parser_find_keyword(text,&text);
    for(index = 0;index<80;index++)
    {
        lt.line.args[index] = text[index];
        if(text[index] == 0)
        {
            break;
        }
    }
    parser_parse_line(&lt.line);
}

void parser_parse_line(__eds__ program_line *text)
{
    int kw;
    if(text->cmd > 128)
    {
        kw = text->cmd-128;
        if(keywords[kw].handler!=0)
        {
            keywords[kw].handler(text);
        }
    }
}
