#!/bin/bash

#CYGWIN
CC="/cygdrive/c/Program Files (x86)/Microchip/xc16/v1.36/bin/xc16-gcc.exe"

BIN2HEX="/cygdrive/c/Program Files (x86)/Microchip/xc16/v1.36/bin/xc16-bin2hex.exe"

CFLAGS="-mcpu=24FJ256DA206 -mlarge-arrays -mlarge-code -Wall"
SRCDIR=src
INCDIR=inc/
OUTDIR=out
CFLAGS="${CFLAGS} -I${INCDIR}"

src=$(ls ${SRCDIR})
elem=""
obj=""
for s in $src
do
    elem="${elem} ${s%.c}"
    obj="${obj} ${s%.c}.o"
done

for e in ${elem}
do
    "${CC}" ${SRCDIR}/${e}.c -c -o ${OUTDIR}/${e}.o ${CFLAGS}
    OBJS="${OBJS} ${OUTDIR}/${e}.o"
done


"${CC}" ${OBJS} -o ${OUTDIR}/demo.elf -mcpu=24FJ256DA206 -omf=elf -mlarge-arrays -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,,--script=p24FJ256DA206.gld,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map=production.map,--report-mem > meminfo.log

"${BIN2HEX}" ${OUTDIR}/demo.elf -a  -omf=elf
