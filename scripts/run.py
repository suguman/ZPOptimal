import os
import sys

benchmarkdir = "../finalbenchmarks/"

outputdir = "../output/"

srcfile = "../src/./test"

df = 2

v = 3

## TIMEOUT
timeout = 500

fname = open("benchmarksfilename.txt")

line = fname.readline().strip()
i = 0
while(line!=""):

    filenametemp = line.split(":")[0].split("/")
    filename = "/".join([filenametemp[2], filenametemp[3]])
    print(i)
    print(filename)

    inputfilename = benchmarkdir + filename
    outputfilename = outputdir + filename

    commandline = " ".join(["timeout ", str(timeout), "time", srcfile, inputfilename, str(df), str(v), "safety"])
    print(commandline)
    os.system(commandline)

    line = fname.readline().strip()

    i+=1
