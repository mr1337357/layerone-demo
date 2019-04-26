#!/bin/bash

#CYGWIN
CC="/cygdrive/c/Program Files (x86)/Microchip/xc16/v1.36/bin/xc16-gcc.exe"
BIN2HEX="/cygdrive/c/Program Files (x86)/Microchip/xc16/v1.36/bin/xc16-bin2hex.exe"

mkdir output

CFLAGS="-mcpu=24FJ256DA206 -mlarge-arrays"
SRCDIR=demoboard.X
OUTDIR=output

"${CC}" ${SRCDIR}/main.c -c -o ${OUTDIR}/main.o ${CFLAGS}
"${CC}" ${SRCDIR}/audio.c -c -o ${OUTDIR}/audio.o ${CFLAGS}
"${CC}" ${SRCDIR}/gfx.c -c -o ${OUTDIR}/gfx.o ${CFLAGS}
"${CC}" ${SRCDIR}/mandelbrot.c -c -o ${OUTDIR}/mandelbrot.o ${CFLAGS}
"${CC}" ${SRCDIR}/uart.c -c -o ${OUTDIR}/uart.o ${CFLAGS}


"${CC}" ${OUTDIR}/main.o ${OUTDIR}/mandelbrot.o ${OUTDIR}/audio.o ${OUTDIR}/gfx.o ${OUTDIR}/uart.o -o ${OUTDIR}/demo.elf -mcpu=24FJ256DA206 -omf=elf -mlarge-arrays -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,,--script=p24FJ256DA206.gld,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map=production.map,--report-mem > meminfo.log

"${BIN2HEX}" ${OUTDIR}/demo.elf -a  -omf=elf
