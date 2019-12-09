// Knight Moves
// UVa ID: 439
// Verdict: Accepted
// Submission Date: 09/12/2019
// Run Time: 0.050 secs
//
// Author: Borja Gomez

#include <iostream>
#include <queue>

using namespace std;

#define N 8

struct Node {

    int x;
    int y;
    bool visited;
    int dist;

    Node(int x, int y, bool visited, int dist = 0): x(x), y(y), visited(visited), dist(dist) {}

};

queue<Node> q;

int knight_moves[2][N] = {-1,-1,1, 1,2, 2,-2,-2,
                           2,-2,2,-2,1,-1, 1,-1};

int bfs(int c1, int c2, int r1, int r2)
{
    q.push({r1, c1, false, 0});

    while(!q.empty())
    {
        Node node = q.front();
        q.pop();

        int x = node.x;
        int y = node.y;

        if(r2 == x && c2 == y)
        {
            return node.dist;
        }

        if(!node.visited)
        {
            node.visited = true;
            for(int i = 0; i < N; i++)
            {
                int next_x = x + knight_moves[0][i];
                int next_y = y + knight_moves[1][i];

                if(next_x >= 1 && next_y >= 1 && next_x <= N && next_y <= N)
                {
                    q.push({next_x, next_y, false, node.dist + 1});
                }
            }
        }
    }

    return -1;
}

int main()
{
    int c1, c2, r1, r2;

    string s1, s2;
    while(cin >> s1 >> s2)
    {
        c1 = s1[0] - 'a' + 1;
        c2 = s2[0] - 'a' + 1;
        r1 = s1[1] - '0';
        r2 = s2[1] - '0';

        int moves = bfs(c1, c2, r1, r2);

        queue<Node> _empty;
        swap(q, _empty);

        cout << "To get from " << s1 << " to " << s2 << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}
