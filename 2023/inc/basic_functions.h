#include <xc.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#ifndef BASIC_FUNCTIONS_H
#define	BASIC_FUNCTIONS_H

//STRUCTURES
typedef struct 
{
    uint16_t lineno;
    uint8_t len;
    uint8_t cmd;
    uint8_t args[];
} program_line;

typedef struct 
{
    char *name;
    void (*handler)(__eds__ program_line *);
} keyword;

typedef struct
{
    char name[10];
    int32_t value;
} variable;

//GLOBALS
extern int debug_level;

//FUNCTIONS

//EDITOR
void editor_list();
int editor_run();

//PARSER
uint8_t parser_find_keyword(char *cmd,char **consume);
__eds__ uint8_t *parser_get_token(__eds__ uint8_t **text);
void parser_handle_list(char *args);
void parser_parse_text(char *text);
void parser_parse_line(__eds__ program_line *text);

//PROGRAM MEMORY
char program_is_code(char *str);
void program_init(__eds__ uint8_t *mem, uint32_t len);
void program_move_code(__eds__ uint8_t *old, __eds__ uint8_t *new,int len);
void program_insert_line(program_line *l,char *args);
void program_add_line(char *input);
__eds__ program_line *program_get_line(uint16_t pc);
void program_dump(__eds__ program_line *line);

//INTERPRETER
char interpreter_infix2postfix(__eds__ uint8_t *infix,uint8_t *postfix);
int32_t interpreter_expr(__eds__ uint8_t *line);
void interpreter_if_handler(__eds__ program_line *line);
void interpreter_goto_handler(__eds__ program_line *line);
void interpreter_print_handler(__eds__ program_line *line);
void interpreter_let_handler(__eds__ program_line *line);
void interpreter_run_handler();
void interpreter_gosub_handler(__eds__ program_line *line);
void interpreter_ret_handler();
void interpreter_prints_handler(__eds__ program_line *line);
void interpreter_debug_handler(__eds__ program_line *line);
void interpreter_breakpoint_handler(__eds__ program_line *line);
void interpreter_run();

//VARIABLE
void variable_init();
void variable_create(__eds__ uint8_t *name,int32_t value);
int32_t *variable_get(__eds__ uint8_t *name);
void variable_dump();

//EXTERNAL
void draw_dot(__eds__ program_line *line);
void color_handler(__eds__ program_line *line);

#endif	/* BASIC_FUNCTIONS_H */



