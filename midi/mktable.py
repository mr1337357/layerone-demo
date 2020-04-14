import math
indexes=range(360)
phases=map(lambda x: float(x)/180.0*math.pi,indexes)
cos = map(math.cos,phases)
table = map(lambda x: int(x*16384),cos)
#print table
count = 0
for i in range(len(table)):
    if table[i] < 0:
        table[i]+=0x10000
def tohex(n):
    o=''
    c='0123456789ABCDEF'
    for i in range(4):
        o=c[n%16]+o
        n/=16
    return o

for e in table:
    print '0x{}, '.format(tohex(e)) ,
    if count%16==15:
        print ''
    count+=1
