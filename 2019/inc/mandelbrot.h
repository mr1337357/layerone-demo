#include <stdint.h>
#define FIXED int16_t
#define LONGFIX int32_t

typedef struct complex
{
    FIXED real;
    FIXED imag;
} complex_t;

FIXED fmul(FIXED a, FIXED b);

FIXED fadd(FIXED a, FIXED b);

uint16_t mag(complex_t *a);

void cadd(complex_t *o, complex_t *a, complex_t *b);

//o can be aliased with a and b ;) (for now at least)
void cmul(complex_t *o, complex_t *a, complex_t *b);

uint16_t iterate(complex_t *c);
