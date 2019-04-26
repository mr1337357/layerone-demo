with open('bincolors.txt','r') as bc:
    for l in bc.readlines():
        print hex(int(l,2))
