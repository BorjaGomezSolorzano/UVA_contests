// Broken Keyboard (a.k.a. Beiju Text)
// UVa ID: 11988
// Verdict: Accepted
// Submission Date: 08/12/2019
// Run Time: 0.250 secs
//
// Author: Borja Gomez

#include <iostream>
#include <stdio.h>
#include <list>
#include <iterator>

using namespace std;

list<char> lst;
list<char> aux;

int main()
{
    string str;
    while(getline(cin, str))
    {
        bool _front = false;
        for (int i = 0; i < str.length(); i++)
        {
            if(str[i] == '[')
            {
                _front = true;

                for (list<char>::reverse_iterator rit=aux.rbegin(); rit!=aux.rend(); ++rit)
                {
                    lst.push_front(*rit);
                }
                aux.clear();
            } else if(str[i] == ']') {
                _front = false;
            } else if(_front) {
                aux.push_back(str[i]);
            } else if (!_front) {
                lst.push_back(str[i]);
            }
        }

        for(list <char> :: iterator it = aux.begin(); it != aux.end(); ++it)
        {
            cout << *it;
        }
        for(list <char> :: iterator it = lst.begin(); it != lst.end(); ++it)
        {
            cout << *it;
        }
        cout << '\n';

        lst.clear();
        aux.clear();
    }
    return 0;
}
