// Unique snowflakes
// UVa ID: 11572
// Verdict: Accepted
// Submission Date: 17/12/2019
// Run Time: 0.350 secs
//
// Author: Borja Gomez

#include <iostream>
#include <map>

using namespace std;

int n, current_integer;


int main()
{
    int m;
    while(cin >> m)
    {
        for(int t = 0; t < m; t++)
        {
            cin >> n;

            int max_l = 0;
            int current_subsequence_length = 0;
            int start = 0;

            map<int, int> positions;

            for(int i = 0; i < n; i++)
            {
                cin >> current_integer;

                auto it = positions.find(current_integer);
                if (it != positions.end())
                {
                    int pos = it -> second;
                    start = max(start, pos + 1);

                    it->second = i;
                }
                else
                {
                    positions.insert({current_integer, i});
                }

                current_subsequence_length = i - start + 1;
                max_l = max(max_l, current_subsequence_length);
            }

            cout << max_l << endl;
        }
    }

    return 0;
}

/*
1
5
1
2
3
2
1


*/
