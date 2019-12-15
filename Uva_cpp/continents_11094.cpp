// Continents
// UVa ID: 11094
// Verdict: Accepted
// Submission Date: 16/12/2019
// Run Time: 0.450 secs
//
// Author: Borja Gomez


#include <iostream>


using namespace std;

#define T 20

char land, maps[T][T];
bool visited[T][T];
int M, N, X, Y, land_size;
int adj_x[5]= {0,0,0,1,-1};
int adj_y[5]= {0,1,-1,0,0};

void dfs(int x, int y)
{
    for(int i = 0; i < 5; i++)
    {
        int next_x = x + adj_x[i];
        int next_y = (y + adj_y[i] + N) % N;
        if(next_x >=0 && next_x < M)
        {
            if(maps[next_x][next_y] == land && !visited[next_x][next_y])
            {
                land_size++;
                visited[next_x][next_y] = true;
                dfs(next_x, next_y);
            }
        }
    }
}

int main()
{
    while(cin >> M >> N)
    {
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> maps[i][j];
                visited[i][j] = false;
            }
        }

        cin >> X >> Y;

        land = maps[X][Y];

        dfs(X, Y);

        int max_land = 0;
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(!visited[i][j] && maps[i][j] == land)
                {
                    land_size = 0;
                    dfs(i, j);
                    max_land = max(max_land, land_size);
                }
            }
        }

        cout << max_land << endl;
    }

    return 0;
}

/*
5 5
wwwww
wwllw
wwwww
wllww
wwwww
1 3

*/
