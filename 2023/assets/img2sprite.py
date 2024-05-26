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

#if im.size != (16,16):
#   print('wrong size. should be 16x16')
#   sys.exit(1)
   
colors={}
colorlist=[]
pixels=[]
w,h=im.size
for y in range(h):
   for x in range(w):
      pix = im.getpixel((x,y))
      if not pix in colors:
         colors[pix]=len(colors)
         colorlist.append(pix)
      pixels.append(colors[pix])
if len(colors)>16:
   print('too many colors')
#print(pixels)
with open(outfile,'w') as outfile:

   outfile.write('#define {}_COLORS '.format(spritename))
   for i in range(16):
      color=(0,0,0)
      try:
         color = colorlist[i]
      except:
         pass
      r=color[0]
      g=color[1]
      b=color[2]
      r = int(r/8)
      g = int(g/4)
      b = int(b/8)
      rgb565=r*(2**11)+g*(2**5)+b
      outfile.write('{}, '.format(hex(rgb565)))
   outfile.write('\n')
   outfile.write('#define {}_W {}\n'.format(spritename,w))
   outfile.write('#define {}_H {}\n'.format(spritename,h))
   outfile.write('#define {}_DATA '.format(spritename))
   i=0
   while i < len(pixels):
      byte = pixels[i]
      i+=1
      byte += pixels[i]*16
      i+=1
      outfile.write('{}, '.format(byte))
   outfile.write('\n')
