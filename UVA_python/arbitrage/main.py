import sys
import cProfile

def build_paths2(best, path, n):
    steps,k,i,j = np.mgrid[1:n,0:n,0:n,0:n]
    tmp = best[i, k, steps - 1] * best[k, j, 0]
    a = np.where(best[i, j, steps] < tmp)
    best[i, j, steps][a] = tmp[a]
    path[i, j, steps][a] = k[a]


def build_paths(best, path, n):
    for steps in range(1, n):
        for k in range(0, n):
            for i in range(0, n):
                for j in range(0, n):
                    tmp = best[i,k,steps - 1] * best[k,j,0]
                    if best[i,j,steps] < tmp:
                        best[i,j,steps] = tmp
                        path[i,j,steps] = k


def print_result(best, path, n):
    sequence = False
    for steps in range(1, n):
        if sequence is True:
            break
        for i in range(0, n):
            if best[i,i,steps] > 1.01:
                index = int(i)
                pp = [0 for i in range(steps + 2)]
                pp[steps + 1] = str(index + 1)
                for j in range(steps, -1, -1):
                    v = int(path[i,index,j])
                    pp[j] = str(v + 1)
                    index = v

                print(' '.join(pp))
                sequence = True
                break

    if sequence is False:
        print('no arbitrage sequence exists')


def arbitrage(best, path, n):

    build_paths(best, path, n)

    print_result(best, path, n)

import numpy as np

def fill(line, file):
    n = int(line)
    best = np.asarray(np.zeros((n,n,n)))#[[[0 for k in range(n)] for j in range(n)] for i in range(n)]
    path = np.asarray(np.zeros((n,n,n)))#[[[0 for k in range(n)] for j in range(n)] for i in range(n)]
    for i in range(0, n):
        line = file.readline()
        splited = line.split()
        k = 0
        for j in range(0, n):
            if i != j:
                best[i,j,0] = float(splited[k])
                k += 1
            else:
                best[i,j,0] = 1

            path[i,j,0] = i

    return best, path, n


def main():
    file = open("example_input_2", "r")
    line = file.readline()
    while line:
        best, path, n = fill(line, file)

        arbitrage(best, path, n)

        line = file.readline()

if __name__ == '__main__':
    cProfile.run('main()')