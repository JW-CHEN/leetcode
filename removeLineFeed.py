import sys
import os

def main():
    argv = sys.argv
    f = open(argv[1])
    fw = open(argv[2],"w+");
    for line in f:
        if (line != "\n"):
            fw.write(line)
    os.remove(argv[1])

main()
