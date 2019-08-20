#include <stdint.h>
#define FIXED int16_t
#define LONGFIX int32_t

typedef struct complex
{
    FIXED real;
    FIXED imag;
} complex_t;

FIXED fmul(FIXED a, FIXED b)
{
    LONGFIX m;
    m=a;
    m*=b;
    m>>=14;
    return (FIXED)m;
}

FIXED fadd(FIXED a, FIXED b)
{
    return a+b;
}

uint16_t mag(complex_t *a)
{
    uint16_t mg;
    FIXED is;
    FIXED rs;
    is = fmul(a->real,a->real);
    rs = fmul(a->imag,a->imag);
    is>>=14;
    rs>>=14;
    mg=is+rs;
    return mg;
}

void cadd(complex_t *o, complex_t *a, complex_t *b)
{
    FIXED r;
    FIXED i;
    
    r = fadd(a->real,b->real);
    i = fadd(a->imag,b->imag);
    o->real = r;
    o->imag = i;
}

//o can be aliased with a and b ;) (for now at least)
void cmul(complex_t *o, complex_t *a, complex_t *b)
{
    FIXED r;
    FIXED i;
    r = fmul(a->real,b->real)-fmul(a->imag,b->imag);
    i = fmul(a->real,b->imag)+fmul(a->imag,b->real);
    o->real = r;
    o->imag = i;
}

uint16_t iterate(complex_t *c)
{
    uint16_t steps = 0;
    complex_t z = {0,0};
    while(mag(&z)<2)
    {
        if(steps==255)
        {
            return 255;
        }
        cmul(&z,&z,&z);
        cadd(&z,&z,c);
        steps++;
    }
    return steps;
}

#ifdef PC
#include <stdio.h>

float fix2float(FIXED a)
{
    float f = (float)a;
    f/=16384;
    return f;
}

int main()
{
    complex_t c = {5379,9437};
    uint8_t it;
    FIXED a=0x8000;
    FIXED b=0x8000;
    FIXED ans;
    it = iterate(&c);
    printf("%d\n",it);
    ans = fmul(a,b);
    printf("%f * %f = %f\n",fix2float(a),fix2float(b),fix2float(ans));
    printf("0x%04hX * 0x%04hX = 0x%04hX\n",a,b,ans);
    return 0;
}
#endif