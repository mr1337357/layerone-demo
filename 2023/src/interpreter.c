#include "basic_functions.h"

static uint32_t pc=0;
static uint8_t if_result = 1;
static uint32_t breakpoint = 0;

static uint32_t stack[20];
static uint32_t sp = 0;

static uint8_t precedence(uint8_t operator)
{
    switch(operator)
    {
        case '(':
            return 0;
        case '^':
            return 1;
        case '*':
        case '/':
        case '[':
        case ']':
            return 2;
        case '+':
        case '-':
            return 3;
        case '>':
        case '<':
        case '?':
            return 4;
        case '&':
        case '|':
            return 5;
        case '=':
            return 6;
    }
    return 99;
}

char interpreter_infix2postfix(__eds__ uint8_t *infix,uint8_t *postfix)
{
    uint8_t opstack[10];
    uint8_t opcount = 0;
	__eds__ uint8_t *token;
	while((token = parser_get_token(&infix)))
	{
		if(isalnum(*token) || *token == '_')
		{
			while(*token != 0 && *token != ' ')
			{
				*postfix++ = *token++;
			}
			*postfix++ = ' ';
		}
        else
        {
            if(*token == '(')
            {
                opstack[opcount++] = *token;
            }
            else if(*token == ')')
            {
                while(opstack[--opcount] != '(')
                {
                    if(opcount < 0)
                    {
                        return 0;
                    }
                    *postfix++ = opstack[opcount];
                    *postfix++ = ' ';
                }
            }
            else
            {
                if(*token == ':')
                {
                    break;
                }
                while(opcount > 0 && (precedence(opstack[opcount-1]) <= precedence(*token)))
                {
                    *postfix++ = opstack[--opcount];
                    *postfix++ = ' ';
                }
                opstack[opcount++] = *token;
            }
        }
	}
    while(opcount)
    {
        *postfix++ = opstack[--opcount];
        *postfix++ = ' ';
    }
	*postfix++ = 0;
	return 1;
}

int32_t interpreter_postfix2num(uint8_t *line)
{
    int32_t neg = 1;
    int32_t tempnum;
    int32_t *nump;
    int32_t numbuff[20];
    int32_t numcount = 0;
    int32_t *numstack[10];
    uint8_t stackcount = 0;
    __eds__ uint8_t *eline = (__eds__ uint8_t *)line;
    __eds__ uint8_t *token;
	while((token = parser_get_token(&eline)))
    {
        if(isalpha(*token))
        {
            //variable
            nump = variable_get(token);
            if(nump == 0)
            {
                fprintf(stderr,"bad variable name\n");
                return 0;
            }
            numstack[stackcount] = nump;
            stackcount++;
        }
        else if(isdigit(*token) || *token == '_')
        {
            if(*token == '_')
            {
                token++;
                neg = -1;
            }
            tempnum = 0;
            while(isdigit(*token))
            {
                tempnum = tempnum * 10;
                tempnum += *token - '0';
                token++;
            }
            tempnum *= neg;
            numbuff[numcount] = tempnum;
            numstack[stackcount] = &numbuff[numcount];
            numcount++;
            stackcount++;
        }
        else
        {
            switch(*token++)
            {
                case '=':
                    *numstack[stackcount-2] = *numstack[stackcount-1];
                    stackcount--;
                    break;
                case '?':
                    numbuff[numcount] = *numstack[stackcount-2] == *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case '+':
                    numbuff[numcount] = *numstack[stackcount-2] + *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case '-':
                    numbuff[numcount] = *numstack[stackcount-2] - *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case '*':
                    numbuff[numcount] = *numstack[stackcount-2] * *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case '/':
                    numbuff[numcount] = *numstack[stackcount-2] / *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case '>':
                    numbuff[numcount] = *numstack[stackcount-2] > *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case '<':
                    numbuff[numcount] = *numstack[stackcount-2] < *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case '&':
                    numbuff[numcount] = *numstack[stackcount-2] && *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case '|':
                    numbuff[numcount] = *numstack[stackcount-2] || *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case '[':
                    numbuff[numcount] = *numstack[stackcount-2] >> *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
                case ']':
                    numbuff[numcount] = *numstack[stackcount-2] >> *numstack[stackcount-1];
                    stackcount--;
                    numstack[stackcount - 1] = &numbuff[numcount++];
                    break;
            }
        }
    }
    if(stackcount > 0)
    {
        return *numstack[stackcount-1];
    }
    fprintf(stderr,"didnt get value somehow\n");
    return 0;
}

int32_t interpreter_expr(__eds__ uint8_t *line)
{
    int32_t value;
	uint8_t postfix[80];
	interpreter_infix2postfix(line,postfix);
    value = interpreter_postfix2num(postfix);
    return value;
}

void interpreter_if_handler(__eds__ program_line *line)
{
    int32_t value = interpreter_expr(line->args);
    if_result = value;
}

void interpreter_goto_handler(__eds__ program_line *line)
{
    int32_t value = interpreter_expr(line->args);
    pc = value;
}

void interpreter_print_handler(__eds__ program_line *line)
{
    int32_t value = interpreter_expr(line->args);
    fprintf(stdout,"%ld\n",value);
}

void interpreter_let_handler(__eds__ program_line *line)
{
    __eds__ uint8_t *templine;
    __eds__ uint8_t *var;
    int32_t value;
    templine = line->args;
    var = parser_get_token(&templine);
    variable_create(var,0);
    value = interpreter_expr(line->args);
}

void interpreter_gosub_handler(__eds__ program_line *line)
{
    stack[sp++] = pc + 1;
    interpreter_goto_handler(line);
}

void interpreter_ret_handler()
{
    pc = stack[--sp];
}

void interpreter_prints_handler(__eds__ program_line *line)
{
    __eds__ uint8_t *s;
    s = line->args;
    while(*s)
    {
        fputc(*s,stdout);
        s++;
    }
    fputc('\n',stdout);
}

void interpreter_debug_handler(__eds__ program_line *line)
{
    int32_t value = interpreter_expr(line->args);
    debug_level = value;
}
void interpreter_breakpoint_handler(__eds__ program_line *line)
{
    int32_t value = interpreter_expr(line->args);
    breakpoint = value;
}

void interpreter_run()
{
    __eds__ program_line *line;
    while((line = program_get_line(pc)))
    {
        if(breakpoint > 0 && breakpoint == line->lineno)
        {
            break;
        }
        if(debug_level >= 1)
        {
            fprintf(stderr,"PC %d\n",line->lineno);
        }
        pc = line->lineno + 1;
        if(if_result == 0)
        {
            if_result = 1;
        }
        else
        {
            parser_parse_line(line);
        }
    }
}

void interpreter_run_handler()
{
    pc=0;
    interpreter_run();
}
