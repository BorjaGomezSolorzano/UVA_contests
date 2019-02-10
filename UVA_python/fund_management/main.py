import sys
import re

if __name__ == '__main__':
    file = open("example_input", "r")
    line = file.readline()
    while line:
        spt = line.strip().split()
        c = float(spt[0])
        m = int(spt[1])
        n = int(spt[2])
        k = int(spt[3])
        M=[[0 for k in range(m)] for j in range(n)]
        dict = {}
        for i in range(2*n):
            spt = file.readline().strip().split()
            if i % 2 == 0:
                item=spt[0]
                lot_size=int(spt[1])
                k_i=int(spt[2])
                idx=int(i/2)
                dict[item]=(idx,lot_size,k_i)
            else:
                for j in range(m):
                    M[idx][j]=spt[j]




        line = file.readline()