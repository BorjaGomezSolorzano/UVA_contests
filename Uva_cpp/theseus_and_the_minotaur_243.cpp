// Theseus and the Minotaur (II)
// UVa ID: 243
// Verdict: Time Limit
// Submission Date: ?
// Run Time: ?
//
// Author: Borja Gomez

#include<iostream>
#include <stdio.h>
#include <string>

using namespace std;

#define n 26

int m_from, m_to, t_from, t_to;
int n_caves[n], caves[n][n], minotaur_exit[n][2];
bool light[n][2];


void restart()
{
    for(int from_cave = 0; from_cave < n; from_cave++)
    {
        minotaur_exit[from_cave][0] = -1;
        minotaur_exit[from_cave][1] = -1;
        light[from_cave][0] = false;
        light[from_cave][1] = false;
        n_caves[from_cave] = 0;
        for(int to_cave = 0; to_cave < n; to_cave++)
        {
            caves[from_cave][to_cave] = 0;
        }
    }
}

int search_idx(int from_cave, int to_cave)
{
    for(int i = 0; i < n_caves[to_cave]; i++)
    {
        if(caves[to_cave][i] == from_cave)
        {
            return i;
        }
    }
    return -1;
}

int minotaur_moves()
{
    int start = search_idx(m_from, m_to);
    if(start >= 0) {
        for(int exit = 0; exit < n_caves[m_to]; exit++)
        {
            int cave = caves[m_to][(start - 1 - exit + n_caves[m_to]) % n_caves[m_to]];
            //cout << "Cave " << (char)('A' + cave) << " lighted? " << light[cave][1] << endl;
            if(!light[cave][1])
            {
                if(minotaur_exit[cave][1] < 0)
                {
                    //cout << "Minotaur enter's in " << (char)('A' + cave) << " from " << (char)('A' + m_to) << endl;
                    minotaur_exit[m_to][0] = cave;
                    m_from = m_to, m_to = cave;

                    return 0;
                }
            } else {
                if (t_from == cave && t_to == m_to)
                {
                    cout << "Theseus is killed between " << (char)('A' + t_from) << " and " << (char)('A' + t_to) << endl;

                    return 1;
                }
                //cout << "Minotaur back's to " << (char)('A' + m_to) << " cave lighted " << (char)('A' + cave) << endl;
                m_from = m_to;

                return 0;
            }
        }
        m_from = m_to;
    } else {
        m_from = m_to;
    }

    return 0;
}

int theseus_moves()
{
    if(minotaur_exit[t_to][1] >= 0)
    {
        //cout << "Theseus follow's minotaur in " << (char)('A' + minotaur_exit[t_to][1]) << " " << minotaur_exit[t_to][1] << endl;
        t_from = t_to, t_to = minotaur_exit[t_to][1];
        light[t_to][0] = true;
    }
    else {
        int start = search_idx(t_from, t_to);
        if(start >= 0)
        {
            for(int exit = 0; exit < n_caves[t_to]; exit++)
            {
                int cave = caves[t_to][(start + 1 + exit) % n_caves[t_to]];
                if(!light[cave][1])
                {
                    //cout << "Theseus enter's in " << (char)('A' + cave) << " from " << (char)('A' + t_to) << endl;
                    t_from = t_to, t_to = cave;
                    light[cave][0] = true;

                    return 0;
                }
            }
            t_from = t_to;
        } else {
            t_from = t_to;
        }
    }
    return 0;
}

void update()
{
    for(int from_cave = 0; from_cave < n; from_cave++)
    {
        minotaur_exit[from_cave][1] = minotaur_exit[from_cave][0];
        light[from_cave][1] = light[from_cave][0];
    }
}

int main()
{
    restart();

    string line;
    while (getline(cin, line), line[0] != '#')
    {
        if(line[0] == '@')
        {
            t_from = line[1] - 'A', t_to = line[2] - 'A';
            m_from = line[3] - 'A', m_to = line[4] - 'A';

            minotaur_exit[m_from][1] = m_to;
            light[t_to][1] = true;

            while (1)
            {
                if(t_to == m_to)
                {
                    cout << "The Minotaur is slain in " << (char)('A' + t_to) << endl;
                    break;
                }

                else if(t_from == m_to && t_to == m_from)
                {
                    cout << "Theseus is killed between " << (char)('A' + t_from) << " and " << (char)('A' + t_to) << endl;
                    break;
                }

                theseus_moves();

                if(minotaur_moves() == 1)
                {
                    break;
                }

                update();

            }

            restart();
        }
        else {
            int src_cave = line[0] - 'A';
            for (unsigned int i = 2; i < line.length(); i++)
            {
                caves[src_cave][n_caves[src_cave]] = line[i] - 'A';
                n_caves[src_cave] += 1;
            }
        }
    }

    return(0);
}


