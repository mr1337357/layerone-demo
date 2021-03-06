#!/bin/bash

load() {
   $LOADER -f=out/demo.hex -d=pic24fj256da206 -k=/dev/ttyACM0 -r=115200 --writef -o

}

host=$(uname -s)
case $host in
   Linux*)
      CC="/opt/microchip/xc16/v1.50/bin/xc16-gcc"
      BIN2HEX="/opt/microchip/xc16/v1.50/bin/xc16-bin2hex"
      LOADER="mono ds30LoaderConsole.exe"
      ;;
   CYGWIN*)
      CC="/cygdrive/c/Program Files (x86)/Microchip/xc16/v1.36/bin/xc16-gcc.exe"
      BIN2HEX="/cygdrive/c/Program Files (x86)/Microchip/xc16/v1.36/bin/xc16-bin2hex.exe"
      LOADER="ds30LoaderConsole.exe"
      ;;
   *)
      echo Unknown platform $host
      exit 1
esac

CFLAGS="-mcpu=24FJ256DA206 -mlarge-arrays -mlarge-code -Wall"
SRCDIR=src
INCDIR=inc/
OUTDIR=out
CFLAGS="${CFLAGS} -I${INCDIR} -O2"

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
    if [ "$?" -ne "0" ]
    then
      echo "build failed"
      exit 1
    fi
    OBJS="${OBJS} ${OUTDIR}/${e}.o"
done


"${CC}" ${OBJS} -o ${OUTDIR}/demo.elf -O2 -mcpu=24FJ256DA206 -omf=elf -mlarge-arrays -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,,--script=p24FJ256DA206.gld,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--no-force-link,--smart-io,-Map=production.map,--report-mem > meminfo.log

if [ "$?" -ne "0" ]
then 
   echo "build failed"
   exit 1
fi

"${BIN2HEX}" ${OUTDIR}/demo.elf -a  -omf=elf
if [ "$?" -ne "0" ]
then 
   echo "build failed"
   exit 1
fi

load
