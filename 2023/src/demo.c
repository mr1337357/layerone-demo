#include <stdint.h>

int demo_index = 0;
volatile uint32_t demo_timeout = 1000000;
const char demo[] = "1 REM MANDELBROT BASIC\n2 LET X = 0\n3 LET Y = 0\n4 LET R = _4096\n5 LET I = 3500\n6 LET COUNT = 0\n7 CLEAR\n8 GOSUB 400\n10 GOSUB 200\n20 DOT X : Y : COUNT\n30 LET X = X + 1\n40 LET R = R + 82\n50 IF X < 100\n60 GOTO 10\n70 LET X = 0\n80 LET R = _4096\n90 LET Y = Y + 1\n100 LET I = I - 82\n110 IF Y < 100\n120 GOTO 10\n130 GOTO 9999\n200 REM ITERATION\n210 LET CR = R\n220 LET CI = I\n230 LET COUNT = 0\n240 IF CR * CR ] 11 + CI * CI ] 11 > 4096\n250 RET\n260 LET CRR = CR * CR ] 11 - CI * CI ] 11 + R\n270 LET CII = CR * CI * 2 ] 11 + I\n280 LET CR = CRR\n290 LET CI = CII\n300 LET COUNT = COUNT + 1\n310 IF COUNT > 10\n320 RET\n330 GOTO 240\n400 LET G = 1\n401 COLOR G : 31 : G * 4 : 0\n402 LET G = G + 1\n403 IF G < 16\n404 GOTO 401\n405 RET\nCLEAR\nHACKING GIBSON...............................\nCLEAR\nFINDING TRASH FILE...........................\nCLEAR\nDOWNLOADING..................................\nCLEAR\nRUN\n";
void demo_disable()
{
    demo_timeout = 0;
}
uint8_t demo_has_byte()
{
    if(demo_timeout == 0)
    {
        return 0;
    }
    demo_timeout--;
    if(demo_timeout == 1)
    {
        demo_timeout=6000;
        return 1;
    }
    return 0;
}
uint8_t demo_get_byte()
{
    if(demo_index < sizeof(demo))
    {
        return demo[demo_index++];
    }
    return 0;
}
