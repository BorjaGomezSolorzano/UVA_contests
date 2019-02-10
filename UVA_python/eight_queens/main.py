import sys

m = 8

def isSafe(q, n):
    for i in range(0, n):
        if (q[i] == q[n]) or ((q[i] - q[n]) == (n - i)) or ((q[n] - q[i]) == (n - i)):
            return False
    return True

def print_solution(c):
    aux = ''
    for i in range(0, len(solution)):
        if i > 0:
            aux += ' '
        aux += str(solution[i] + 1)

    print((" " if c[0] <= 9 else "") + str(c[0]) + "      " + aux)


def recursion(c, col, solution, col_0):
    if col == m:
        print_solution(c)
        c[0] += 1
    elif col != col_0:
        for row in range(0, m):
            solution[col] = row
            if isSafe(solution, col) is True:
                recursion(c, col + 1, solution, col_0)
    elif isSafe(solution, col) is True:
        recursion(c, col + 1, solution, col_0)


if __name__ == '__main__':
    #file = open("example_input_1", "r")
    file = sys.stdin
    n = int(file.readline())
    for i in range(0,2*n):
        if i % 2 == 0:
            file.readline()
        else:

            x_y = file.readline().split()

            x_0 = int(x_y[0])-1
            y_0 = int(x_y[1])-1

            solution = [0 for i in range(m)]
            solution[y_0] = x_0

            if i > 1:
                print()

            print('SOLN       COLUMN' + "\n" + ' #      1 2 3 4 5 6 7 8' + "\n")

            recursion([1], 0, solution, y_0)
