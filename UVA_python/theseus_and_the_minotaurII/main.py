import sys

def generate_matrix(n):
    adjacency_list = [[0 for k in range(n)] for j in range(n)]
    adjacency_list_count = [0 for k in range(n)]
    candle = [[False for k in range(2)] for k in range(n)]
    minotaur_visited = [[False for k in range(2)] for k in range(n)]
    theseus_visited = [[False for k in range(2)] for k in range(n)]

    return adjacency_list, adjacency_list_count, candle, minotaur_visited, theseus_visited

if __name__ == '__main__':

    bug = False
    n = 26

    adjacency_list, adjacency_list_count, candle, minotaur_visited, theseus_visited = generate_matrix(n)

    file = sys.stdin
    file = open("example_input", "r")
    for line in file:
        if '#' in line:
            break

        if '@' in line:
            m_prev = ord(line[3]) - ord('A')
            m_start = ord(line[4]) - ord('A')
            t_prev = ord(line[1]) - ord('A')
            t_start = ord(line[2]) - ord('A')

            pursuit = False

            theseus_visited[t_start][0] = True
            minotaur_visited[m_start][0] = True
            theseus_visited[t_start][1] = True
            minotaur_visited[m_start][1] = True

            while (True):

                # Minotaur moves
                #print('Minotaur prev '+chr(m_prev + ord('A')) + ' Minotaur start '+chr(mStart + ord('A')))
                i = adjacency_list[m_start].index(m_prev)
                i = (i - 1 + adjacency_list_count[m_start]) % adjacency_list_count[m_start]
                for count in range(adjacency_list_count[m_start]):
                    c = adjacency_list[m_start][i]
                    i = (i - 1 + adjacency_list_count[m_start]) % adjacency_list_count[m_start]
                    if candle[c][0] is True:
                        print('Minotaur finds candle in '+chr(c + ord('A')))
                        break
                    if minotaur_visited[c][0] is False:
                        print('Minotaur exists ' + chr(c + ord('A')))
                        m_prev = m_start
                        m_start = c
                        minotaur_visited[c][1] = True
                        break

                # Theseus moves
                if minotaur_visited[t_start][0] == True:
                    pursuit = True
                    candle[t_start][1] = True

                i = adjacency_list[t_start].index(t_prev)
                i = (i + 1 + adjacency_list_count[t_start]) % adjacency_list_count[t_start]
                for count in range(adjacency_list_count[t_start]):
                    c = adjacency_list[t_start][i]
                    i = (i + 1 + adjacency_list_count[t_start]) % adjacency_list_count[t_start]
                    if pursuit:
                        if minotaur_visited[c][0] is True and theseus_visited[c][0] is False:
                            t_prev = t_start
                            t_start = c
                            theseus_visited[c][1] = True
                            print('Theseus pursuits ' + chr(c + ord('A')))
                            candle[c][1] = True
                            break
                    else:
                        if theseus_visited[c][0] is False:
                            print('Theseus exists ' + chr(c + ord('A')))
                            t_prev = t_start
                            t_start = c
                            theseus_visited[c][1] = True
                            break

                #Update turn
                for i in range(n):
                    candle[i][0] = candle[i][1]
                    minotaur_visited[i][0] = minotaur_visited[i][1]
                    theseus_visited[i][0] = theseus_visited[i][1]

                #Resolve
                if t_start == m_start:
                    print("The Minotaur is slain in " + chr(t_start + ord('A')));
                    break

                if t_start == m_prev and m_start == t_prev:
                    print("Theseus is killed between " + chr(t_prev + ord('A')) + " and " + chr(t_start + ord('A')));
                    break

            #Restart the laberinth
            adjacency_list, adjacency_list_count, candle, minotaur_visited, theseus_visited = generate_matrix(n)

        else:
            v = line.strip().split(":")
            if len(v) > 1:
                src = ord(v[0]) - ord('A')
                for i in range(len(v[1])):
                    adjacency_list[src][adjacency_list_count[src]] = ord(v[1][i]) - ord('A')
                    adjacency_list_count[src] += 1

    exit(0)