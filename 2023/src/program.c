#include "basic_functions.h"

__eds__ uint8_t *program;
uint32_t progsize;
uint32_t proglen;

char program_is_code(char *str)
{
    char iscode = 0;
    if(!isdigit(*str++))
    {
        return 0;
    }
    while(iscode<5)
    {
        if(*str == ' ')
        {
            return 1;
        }
        else if(isdigit(*str++))
        {
            iscode++;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

void program_init(__eds__ uint8_t *mem, uint32_t len)
{
    program = mem;
    proglen = 0;
    for(progsize=0;progsize<len;progsize++)
    {
        program[progsize]=0;
    }
}

void program_move_code(__eds__ uint8_t *old, __eds__ uint8_t *new,int len)
{
    int i;
    if(old > new)
    {
        for(i = 0; i < len ; i++)
        {
            new[i] = old[i];
        }
        
    }
    if(new > old)
    {
        for(i = len - 1; i >= 0; i--)
        {
            new[i] = old[i];
        }
    }
}

void program_insert_line(program_line *l,char *args)
{
    int i;
    union
    {
        __eds__ program_line *lp;
        __eds__ uint8_t *tp;
    } p;
    p.lp = (__eds__ program_line *)program;
    while((p.lp->lineno < l->lineno) && p.lp->lineno != 0)
    {
        if(p.lp->lineno == 0)
        {
            break;
        }
        if(p.lp->len == 0)
        {
            break;
        }
        p.tp += p.lp->len;
    }

    if(p.lp->lineno == l->lineno)
    {
        program_move_code((__eds__ uint8_t *)(p.tp+p.lp->len),(__eds__ uint8_t *)(p.tp+l->len),(proglen+program-p.tp+p.lp->len));
    }
    else if(p.lp->lineno > l->lineno)
    {
        program_move_code((__eds__ uint8_t *)(p.tp),(__eds__ uint8_t *)(p.tp+l->len),(proglen+program-p.tp));
    }
    p.lp->lineno = l->lineno;
    p.lp->len = l->len;
    p.lp->cmd = l->cmd;
    for(i=0;i<l->len-4;i++)
    {
        p.lp->args[i] = args[i];
    }
}

void program_dump(__eds__ program_line *line)
{
    int i;
    for(i=0;i<100;i++)
    {
        fprintf(stderr,"%02X ",program[i]);
    }
}

void program_add_line(char *input)
{
    program_line l;
    l.lineno = strtol(input,&input,10);
    input++;
    l.cmd = parser_find_keyword(input,&input);
    if(l.cmd)
    {
        input++;
    }
    l.len = strlen(input) + 6;
    l.len &= ~1;
    program_insert_line(&l,input);
}

__eds__ program_line *program_get_line(uint16_t pc)
{
    union
    {
        __eds__ program_line *lp;
        __eds__ uint8_t *tp;
    } p;
    p.lp = (__eds__ program_line *)program;
    while(p.lp->lineno > 0 && p.lp->lineno < pc)
    {
        p.tp+= p.lp->len;
    }
    if(p.lp->lineno == 0)
    {
        return 0;
    }
    return p.lp;
}
