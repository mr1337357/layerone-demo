buf = []
with open("GFXDisplayBuffer.csv","r") as gdb:
    lines = gdb.readlines()
    for line in lines:
        offset = line[17:]
        val = line[-4:-2]
        buf.append(int(val,16))
#print(buf)
prog = buf[38400:]
i = 0
while i < len(buf):
    if buf[i] > 0:
        print('{}: {}'.format(i,hex(buf[i])))
    i+=1
