#include "basic_functions.h"

#include "gfx.h"
#include "gpu.h"

__eds__ uint8_t *find_separator(__eds__ uint8_t *text)
{
    while(*text != 0 && *text != ':')
    {
        text++;
    }
    return text;
}

void draw_dot(__eds__ program_line *line)
{
    int x,y;
    __eds__ uint8_t *expr;
    uint32_t h;
    uint32_t v;
    uint32_t c;
    expr = line->args;
    h = interpreter_expr(expr);
    expr = find_separator(expr);
    expr++;
    v = interpreter_expr(expr);
    expr = find_separator(expr);
    expr++;
    c = interpreter_expr(expr);
    for(x=16;x<19;x++)
    {
        for(y=16;y<19;y++)
        {
            gfx_drawpixel(3 * h + x,3 * v + y,c);
        }
    }
}

void color_handler(__eds__ program_line *line)
{
    int i;
    int r;
    int g;
    int b;
    __eds__ uint8_t *expr;
    expr = line->args;
    i = interpreter_expr(expr);
    expr = find_separator(expr);
    expr++;
    r = interpreter_expr(expr);
    expr = find_separator(expr);
    expr++;
    g = interpreter_expr(expr);
    expr = find_separator(expr);
    expr++;
    b = interpreter_expr(expr);
    expr = find_separator(expr);
    expr++;
    gpu_clut_set(i,(r<<11)|(g<<5)|(b));
}