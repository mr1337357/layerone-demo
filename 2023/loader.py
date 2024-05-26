import sys
import serial
import time

prog = open(sys.argv[1],'r')

ser = serial.Serial("COM8",timeout=1)
for line in prog.readlines():
    #enc = line.encode()
    for c in line:
        sys.stdout.write(c)
        ser.write(c.encode())
        time.sleep(.01)
while True:
    b = ser.read(1)
    sys.stdout.write(b.decode())