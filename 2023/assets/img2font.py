#!/usr/bin/python3
import argparse
from PIL import Image
import sys

fontname=""

#todo argparse
if len(sys.argv) > 1:
   fontname=sys.argv[1]   

infile=fontname+".png"
outfile=fontname+".h"

im = Image.open(infile)

pixels=[]
w,h=im.size
sprites = []
for s in range(w//8):
    pixels = {}
    for y in range(8):
        for x in range(8):
            pix = im.getpixel((x+s*8,y))
            if pix[0]:
                pixels[(x,y)] = 0
            else:
                pixels[(x,y)] = 1
    sprites.append(pixels)
    
with open(outfile,'w') as outfile:
    outfile.write('#define {}_W {}\n'.format(fontname,w))
    outfile.write('#define {}_H {}\n'.format(fontname,h))
    outfile.write('#define {}_DATA '.format(fontname))
    for s in sprites:
        for y in range(8):
            for x in range(8):
                o = ' '
                if s[(x,y)] == 1:
                    o = '*'                    
                sys.stdout.write(o)
            sys.stdout.write('\n')
        sys.stdout.write('\n')
    for s in sprites:
        for y in range(8):
            for x in range(4):
                a = s[(2*x,y)] * 15
                b = s[(2*x+1,y)] * 240
                byte = a + b
                outfile.write('{}, '.format(byte))
    outfile.write('\n')
