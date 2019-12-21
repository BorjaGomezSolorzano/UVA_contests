// Argus
// UVa ID: 1203
// Verdict: Accepted
// Submission Date: 21/12/2019
// Run Time: 0.290 secs
//
// Author: Borja Gomez


#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Register
{
    unsigned int q_num;
    unsigned int time;

    Register(unsigned int q_num, unsigned int time): q_num(q_num), time(time) {}

    friend bool operator>(const Register& l, const Register& r)
    {
        if(l.time > r.time)
        {
            return true;
        }
        else if(l.time == r.time && l.q_num > r.q_num)
        {
            return true;
        }
        return false;
    }
};


priority_queue<Register, vector<Register>, greater<vector<Register>::value_type>> q;
unsigned int q_nums[1000], periods[1000];


int main()
{
    string s;
    unsigned int q_num, period, k;
    unsigned int i = 0;
    while(cin >> s)
    {
        if(s[0] == '#')
        {
            cin >> k;

            for(unsigned int j = 0; j < k; j++)
            {
                for(unsigned int m = 0; m < i; m++)
                {
                    Register reg(q_nums[m], (j + 1) * periods[m]);
                    q.push(reg);
                }
                Register value = q.top();
                cout << value.q_num << endl;

                q.pop();
            }
            break;
        }
        else
        {
            cin >> q_num >> period;

            q_nums[i] = q_num;
            periods[i] = period;
            i++;
        }
    }

    return 0;
}
