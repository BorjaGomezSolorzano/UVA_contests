// Slash Maze
// UVa ID: 705
// Verdict: Accepted
// Submission Date: 15/12/2019
// Run Time: 0 secs
//
// Author: Borja Gomez


#include <iostream>

using namespace std;

#define N 4

bool _is_cyclic, a[250][250];
int h, w, cycle_length, c;
int adj_x[N]= {0,0,1,-1};
int adj_y[N]= {1,-1,0,0};


void is_cyclic(int x, int y)
{
    for(int i = 0; i < N; i++)
    {
        int next_x = x + adj_x[i];
        int next_y = y + adj_y[i];
        if(next_x >=0 && next_x < h && next_y >= 0 && next_y < w)
        {
            if(!a[next_x][next_y])
            {
                cycle_length++;
                a[next_x][next_y] = true;
                is_cyclic(next_x, next_y);
            }
        }
        else
        {
            _is_cyclic = false;
        }
    }
}

void findCycles()
{
    int max_length = -1;
    c++;
    int n_cycles = 0;
    for(int x = 0; x < h; x++)
    {
        for(int y = 0; y < w; y++)
        {
            if(!a[x][y])
            {
                _is_cyclic = true;
                cycle_length = 0;
                is_cyclic(x, y);
                if(_is_cyclic)
                {
                    n_cycles++;
                    max_length = max(max_length, cycle_length);
                }
            }
        }
    }

    cout << "Maze #" << c << ":\n";
    if(max_length != -1)
    {
        cout << n_cycles << " Cycles; the longest has length " << max_length / 3 << ".\n";
    } else {
        cout << "There are no cycles.\n";
    }
    cout << "\n";
}

int main()
{
    int w_aux, h_aux;
    while((cin >> w_aux >> h_aux), w_aux && h_aux)
    {
        h = h_aux * 3;
        w = w_aux * 3;
        for(int x = 0; x < h; x += 3)
        {
            for(int y = 0; y < w; y += 3)
            {
                char c;
                cin>>c;
                if(c == '\\')
                {
                    a[x][y] = a[x + 1][y + 1] = a[x + 2][y + 2] = true;
                }
                else
                {
                    a[x][y + 2] = a[x + 1][y + 1] = a[x + 2][y] = true;
                }
            }
        }

        findCycles();

        for (int x = 0; x < h; x++)
        {
            for (int y = 0; y < w; y++)
            {
                a[x][y] = false;
            }
        }
    }

    return 0;
}

/*
6 4
\//\\/
\///\/
//\\/\
\/\///
3 3
///
\//
\\\
0 0

*/
