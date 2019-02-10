import sys


if __name__ == '__main__':

    n = 26

    file = sys.stdin
    #file = open("example_input_2", "r")
    line = file.readline().strip()
    while(line != '#'):

        adjacency_list = [[0 for k in range(n)] for j in range(n)]
        adjacency_list_count = [0 for k in range(n)]
        candle = [False for k in range(n)]

        vector_1 = line.split(".")
        vector_2 = vector_1[0].split(";")
        for v2 in vector_2:
            vector_3 = v2.split(":")
            if len(vector_3) > 1:
                src = ord(vector_3[0])-ord('A')
                for i in range(len(vector_3[1])):
                    adjacency_list[src][adjacency_list_count[src]]=ord(vector_3[1][i])-ord('A')
                    adjacency_list_count[src] += 1

        vector_4 = vector_1[1].split()
        mStart = ord(vector_4[0]) - ord('A')
        tStart = ord(vector_4[1]) - ord('A')
        k = int(vector_4[2])

        count = 0
        candles_left = []
        while(True):
            #Minotaur moves
            temp = mStart
            for i in range(adjacency_list_count[temp]):
                c = adjacency_list[temp][i]
                if (candle[c] is False) and c != tStart:
                    mStart = c
                    break

            #Theseus moves
            tStart = temp

            if tStart == mStart:
                if len(candles_left) > 0:
                    print(' '.join(candles_left) + ' /' + chr(tStart + ord('A')))
                else:
                    print('/' + chr(tStart + ord('A')))
                break

            if (count+1) % k == 0:
                candle[tStart] = True
                candles_left.append(chr(tStart+ord('A')))

            count += 1

        line = file.readline().strip()

    exit(0)