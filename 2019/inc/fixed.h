#ifndef _FIXED_H_
#define _FIXED_H_

#include <stdint.h>

typedef struct complex
{
    uint16_t real;
    uint16_t imag;
} complex_t;

int16_t fcos(int16_t theta);
int16_t fsin(int16_t theta);
int16_t fmul(int16_t a, int16_t b);

#endif //_FIXED_H_