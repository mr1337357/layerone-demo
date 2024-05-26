#!/bin/bash

XC_VERSION=2.00

debug=0
build=1
asm=0
load=1
fast=0

while [ $# -gt 0 ]
do
   case $1 in
      -a|--assemble)
         asm=1
         ;;
      -d|--debug)
         debug=1
         ;;
      -h|--help)
         #TODO
         exit 0
         ;;
      -l|--load)
         load=1
         ;;
      -b|--build)
         build=1
         ;;
      -nl|--noload)
         load=0
         ;;
      -nb|--nobuild)
         build=0
         ;;
      -f|--fast)
         fast=1
         ;;
      *)
         echo invalid argument: $1
         exit 1
         ;;
   esac
   shift
done

load() {
   $LOADER -f=out/demo.hex -d=pic24fj256da206 -k=/dev/ttyACM0 -r=115200 --writef -o

}

update_assets()
{
   true
}

build() {
   cd ${SRCDIR}
   src=$(ls *.c)
   cd ..
   elem=""
   obj=""
   for s in $src
   do
       elem="${elem} ${s%.c}"
       obj="${obj} ${s%.c}.o"
   done

   for e in ${elem}
   do
       echo "compiling ${e}.c"
       "${CC}" ${SRCDIR}/${e}.c -c -o ${OUTDIR}/${e}.o ${CFLAGS}
       if [ "$?" -ne "0" ]
       then
         echo "build failed"
         exit 1
       fi
       OBJS="${OBJS} ${OUTDIR}/${e}.o"
   done

   echo "linking"
   "${CC}" ${OBJS} -o ${OUTDIR}/demo.elf -O2 -mcpu=24FJ256DA206 -omf=elf -mlarge-arrays -Wl,--local-stack,--script=p24FJ256DA206.gld,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--no-force-link,--smart-io,-Map=production.map,--report-mem > meminfo.log

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
}

host=$(uname -s)
case $host in
   Linux*)
      CC="/opt/microchip/xc16/v${XC_VERSION}/bin/xc16-gcc"
      BIN2HEX="/opt/microchip/xc16/v${XC_VERSION}/bin/xc16-bin2hex"
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

if [ "$debug" == "1" ]
then
   echo "debug build"
   CFLAGS="${CFLAGS} -DDEBUG -g"
fi

if [ "$fast" == "1" ]
then
   CFLAGS="${CFLAGS} -O2"
fi

if [ "$asm" == "1" ]
then
   CFLAGS="${CFLAGS} -S -save-temps"
fi

CFLAGS="${CFLAGS} -mcpu=24FJ256DA206 -mlarge-arrays -mlarge-code -Wall"
SRCDIR=src
INCDIR=inc/
OUTDIR=out
CFLAGS="${CFLAGS} -I${INCDIR}"
if [ "$build" == "1" ]
then
   build
fi
if [ "$load" == "1" ]
then
   load
fi
