// Easy problem from Rujia Liu?
// UVa ID: 11991
// Verdict: Accepted
// Submission Date: 06/12/2019
// Run Time: 0.230 secs
//
// Author: Borja Gomez


#include <stdio.h>
#include <vector>

using namespace std;

#define N 1000000

vector<int> vs[N];

int main()
{
    int n, m, k, v;

    while(scanf("%d %d", &n, &m) == 2)
    {
        for(int v_position = 0; v_position < n; v_position++)
        {
            scanf("%d", &v);
            vs[v - 1].push_back(v_position + 1);
        }

        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &k, &v);

            vector<int> v_positions = vs[v - 1];

            if(v_positions.size() < k)
            {
                printf("%d\n", 0);
            } else {
                printf("%d\n", v_positions[k-1]);
            }
        }

        for(int i = 0; i < N; i++)
        {
            vs[i].clear();
        }
    }

    return(0);
}
