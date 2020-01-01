import os

fname = open("name.txt")

line = fname.readline()
while(line!=""):
    print(line)
    srcname = line.strip()
    destname = srcname.split("/")[-1]
    commandline = " ".join(["cp", srcname, "benchmarks/"+destname])
    print(srcname)
    print(destname)
    print(commandline)
    os.system(commandline)
    line = fname.readline()
    
fname.close()
