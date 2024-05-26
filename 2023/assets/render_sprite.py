#!/usr/bin/python3
import argparse
from PIL import Image
import sys

spritename=""

#todo argparse
if len(sys.argv) > 1:
   spritename=sys.argv[1]   

infile=spritename+".png"
outfile=spritename+".h"

im = Image.open(infile)

if im.size != (16,16):
   print('wrong size. should be 16x16')
   sys.exit(1)
   
colors={}
pixels=[]
w,h=im.size
for y in range(h):
   for x in range(w):
      pix = im.getpixel((x,y))
      if not pix in colors:
         colors[pix]=len(colors)
      pixels.append(colors[pix])
if len(colors)>16:
   print('too many colors')
#print(pixels)
with open(outfile,'w') as outfile:
   outfile.write('#define {}_W 16\n'.format(spritename))
   outfile.write('#define {}_H 16\n'.format(spritename))
   outfile.write('#define {}_DATA '.format(spritename))
   i=0
   while i < len(pixels):
      byte = pixels[i]
      i+=1
      byte += pixels[i]*16
      i+=1
      outfile.write('{}, '.format(byte))
   outfile.write('\n')
