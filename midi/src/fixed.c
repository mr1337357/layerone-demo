#include "fixed.h"

//fixed point 16 bit from -2 to 1.9something
//128 samples
__prog__ static const int16_t costab[] __attribute__((space(prog))) = 
{
    0x4000,  0x3FFD,  0x3FF6,  0x3FE9,  0x3FD8,  0x3FC1,  0x3FA6,  0x3F85,  0x3F60,  0x3F36,  0x3F07,  0x3ED2,  0x3E99,  0x3E5C,  0x3E19,  0x3DD1,
    0x3D85,  0x3D34,  0x3CDE,  0x3C83,  0x3C23,  0x3BBF,  0x3B56,  0x3AE9,  0x3A77,  0x3A00,  0x3985,  0x3906,  0x3882,  0x37F9,  0x376C,  0x36DB,
    0x3646,  0x35AC,  0x350E,  0x346C,  0x33C6,  0x331C,  0x326E,  0x31BC,  0x3106,  0x304D,  0x2F8F,  0x2ECE,  0x2E09,  0x2D41,  0x2C75,  0x2BA5,
    0x2AD3,  0x29FC,  0x2923,  0x2846,  0x2766,  0x2684,  0x259E,  0x24B5,  0x23C9,  0x22DB,  0x21EA,  0x20F6,  0x2000,  0x1F07,  0x1E0B,  0x1D0E,
    0x1C0E,  0x1B0C,  0x1A07,  0x1901,  0x17F9,  0x16EF,  0x15E3,  0x14D6,  0x13C6,  0x12B6,  0x11A4,  0x1090,  0x0F7B,  0x0E65,  0x0D4E,  0x0C36,
    0x0B1D,  0x0A03,  0x08E8,  0x07CC,  0x06B0,  0x0593,  0x0476,  0x0359,  0x023B,  0x011D,  0x0000,  0xFEE3,  0xFDC5,  0xFCA7,  0xFB8A,  0xFA6D,
    0xF950,  0xF834,  0xF718,  0xF5FD,  0xF4E3,  0xF3CA,  0xF2B2,  0xF19B,  0xF085,  0xEF70,  0xEE5C,  0xED4A,  0xEC3A,  0xEB2A,  0xEA1D,  0xE911,
    0xE807,  0xE6FF,  0xE5F9,  0xE4F4,  0xE3F2,  0xE2F2,  0xE1F5,  0xE0F9,  0xE001,  0xDF0A,  0xDE16,  0xDD25,  0xDC37,  0xDB4B,  0xDA62,  0xD97C,
    0xD89A,  0xD7BA,  0xD6DD,  0xD604,  0xD52D,  0xD45B,  0xD38B,  0xD2BF,  0xD1F7,  0xD132,  0xD071,  0xCFB3,  0xCEFA,  0xCE44,  0xCD92,  0xCCE4,
    0xCC3A,  0xCB94,  0xCAF2,  0xCA54,  0xC9BA,  0xC925,  0xC894,  0xC807,  0xC77E,  0xC6FA,  0xC67B,  0xC600,  0xC589,  0xC517,  0xC4AA,  0xC441,
    0xC3DD,  0xC37D,  0xC322,  0xC2CC,  0xC27B,  0xC22F,  0xC1E7,  0xC1A4,  0xC167,  0xC12E,  0xC0F9,  0xC0CA,  0xC0A0,  0xC07B,  0xC05A,  0xC03F,
    0xC028,  0xC017,  0xC00A,  0xC003,  0xC000,  0xC003,  0xC00A,  0xC017,  0xC028,  0xC03F,  0xC05A,  0xC07B,  0xC0A0,  0xC0CA,  0xC0F9,  0xC12E,
    0xC167,  0xC1A4,  0xC1E7,  0xC22F,  0xC27B,  0xC2CC,  0xC322,  0xC37D,  0xC3DD,  0xC441,  0xC4AA,  0xC517,  0xC589,  0xC600,  0xC67B,  0xC6FA,
    0xC77E,  0xC807,  0xC894,  0xC925,  0xC9BA,  0xCA54,  0xCAF2,  0xCB94,  0xCC3A,  0xCCE4,  0xCD92,  0xCE44,  0xCEFA,  0xCFB3,  0xD071,  0xD132,
    0xD1F7,  0xD2BF,  0xD38B,  0xD45B,  0xD52D,  0xD604,  0xD6DD,  0xD7BA,  0xD89A,  0xD97C,  0xDA62,  0xDB4B,  0xDC37,  0xDD25,  0xDE16,  0xDF0A,
    0xE000,  0xE0F9,  0xE1F5,  0xE2F2,  0xE3F2,  0xE4F4,  0xE5F9,  0xE6FF,  0xE807,  0xE911,  0xEA1D,  0xEB2A,  0xEC3A,  0xED4A,  0xEE5C,  0xEF70,
    0xF085,  0xF19B,  0xF2B2,  0xF3CA,  0xF4E3,  0xF5FD,  0xF718,  0xF834,  0xF950,  0xFA6D,  0xFB8A,  0xFCA7,  0xFDC5,  0xFEE3,  0x0000,  0x011D,
    0x023B,  0x0359,  0x0476,  0x0593,  0x06B0,  0x07CC,  0x08E8,  0x0A03,  0x0B1D,  0x0C36,  0x0D4E,  0x0E65,  0x0F7B,  0x1090,  0x11A4,  0x12B6,
    0x13C6,  0x14D6,  0x15E3,  0x16EF,  0x17F9,  0x1901,  0x1A07,  0x1B0C,  0x1C0E,  0x1D0E,  0x1E0B,  0x1F07,  0x2000,  0x20F6,  0x21EA,  0x22DB,
    0x23C9,  0x24B5,  0x259E,  0x2684,  0x2766,  0x2846,  0x2923,  0x29FC,  0x2AD3,  0x2BA5,  0x2C75,  0x2D41,  0x2E09,  0x2ECE,  0x2F8F,  0x304D,
    0x3106,  0x31BC,  0x326E,  0x331C,  0x33C6,  0x346C,  0x350E,  0x35AC,  0x3646,  0x36DB,  0x376C,  0x37F9,  0x3882,  0x3906,  0x3985,  0x3A00,
    0x3A77,  0x3AE9,  0x3B56,  0x3BBF,  0x3C23,  0x3C83,  0x3CDE,  0x3D34,  0x3D85,  0x3DD1,  0x3E19,  0x3E5C,  0x3E99,  0x3ED2,  0x3F07,  0x3F36,
    0x3F60,  0x3F85,  0x3FA6,  0x3FC1,  0x3FD8,  0x3FE9,  0x3FF6,  0x3FFD,
};

int16_t fcos(int16_t theta)
{
    return costab[theta];
}

int16_t fsin(int16_t theta)
{
    if(theta<90)
    {
        theta+=360;
    }
    return costab[theta-90];
}

int16_t fmul(int16_t a, int16_t b)
{
    int32_t m;
    //m=a;
    m=(uint32_t)a*b;
    m>>=14;
    return (int16_t)m;
}

