import sys
with open(sys.argv[1],'r') as inf:
    lines = inf.readlines()
    sys.stdout.write('const char demo[] = "')
    for line in lines:
        sys.stdout.write(line[:-1])
        sys.stdout.write('\\n')
    sys.stdout.write('";')
