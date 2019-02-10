import sys


if __name__ == '__main__':
    caso = 1

    n = int(sys.stdin.readline())
    while n != 0:

        ind = {}

        for i in range(n):
            s1 = sys.stdin.readline().strip()
            ind[s1] = i

        M = [[0 for k in range(n)] for j in range(n)]

        m = int(sys.stdin.readline().strip())

        for i in range(m):
            s = sys.stdin.readline().strip().split()

            s1 = s[0]
            x = float(s[1])
            s2 = s[2]
            M[ind[s1]][ind[s2]] = x

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    M[i][j] = max(M[i][j], M[i][k] * M[k][j])

        exists = False
        for i in range(n):
            if M[i][i] > 1.0:
                exists = True

        result = "Case " + str(caso) + ": "
        caso += 1

        if exists:
            result += "Yes"
        else:
            result += "No"

        print(result)

        sys.stdin.readline()
        n = int(sys.stdin.readline().strip())

    exit(0)