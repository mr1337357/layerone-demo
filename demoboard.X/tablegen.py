from math import sin,pi
import sys
import ctypes

s=[]
os = ''
for sample in u:
    s.append(sample^0x80)
    os += hex(sample^0x80)+', '

#print os
def myhex(n,d=4):
    d=max(d,n.bit_length()/4)
    c='0123456789ABCDEF'
    o=''
    while n:
        print n
        o=c[n%16]+o
        n/=16
        d-=1
    while d:
        o = '0'+o
        d-=1
    o='0x'+o
    return o

def u16(n):
    if n<0:
        return 65536+n
    return n
    


def sine(n=32,a=127,s=1):
    phasestep=2*pi/n
    phase=0.0
    phases=[]
    samples=[]
    for i in range(n):
        phases.append(phase)
        phase+=phasestep
    for p in phases:
        samples.append(sin(p))
    samples = map(lambda s: s*a,samples)
    samples = map(lambda s: int(s),samples)
    samples = map(u16,samples)
    samples = map(myhex,samples)
    return samples
    
def sine(n=32,a=127,s=1):
    phasestep=2*pi/n
    phase=0.0
    phases=[]
    samples=[]
    for i in range(n):
        phases.append(phase)
        phase+=phasestep
    for p in phases:
        samples.append(sin(p))
    samples = map(lambda s: s*a,samples)
    samples = map(lambda s: int(s),samples)
    samples = map(u16,samples)
    samples = map(myhex,samples)
    return samples
    
a = sine(128)
for i,s in enumerate(a):
    sys.stdout.write(s+', ')
    if i%8==7:
        print ''