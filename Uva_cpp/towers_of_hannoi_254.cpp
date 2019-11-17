//http://www.questtosolve.com/browse.php?pid=254

#include <stdio.h>
#include <math.h>

#define N 3

long mod(long a, long b)
{
    return (a % b + b) % b;
}

int main() {

	int n, m, pegs[N]={0};

	while(1) {
        scanf("%d %d\n", &n, &m);
        if(m == 0 && n == 0)
        {
            break;
        }
		for (int i = 0; i < n; i++) {
            int moves = (m + pow(2, i)) / pow(2, i + 1);
            //(m + (1 << i)) >> (i + 1);

            if(i % 2 == 0)
            {
                int l = mod(-moves, N);
                pegs[l]++;
            } else {
                pegs[moves % N]++;
            }
        }

        printf("%d %d %d\n", pegs[0], pegs[1], pegs[2]);
        for(int i = 0; i < N; i++)
        {
            pegs[i] = 0;
        }
	}

	return (0);
}

