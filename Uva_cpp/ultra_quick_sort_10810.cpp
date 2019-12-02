// Ultra quick sort
// UVa ID: 10810
// Verdict: Accepted
// Submission Date: 02/12/2019
// Run Time: 0.080 secs
//
// Author: Borja Gomez

#include <stdio.h>

#define N 500000

long cnt, a[N], la[N], ra[N];


void _merge(long l, long m, long r)
{
     int n1 = m - l + 1;
     int n2 = r - m;

     for(long i = 0; i < n1; i++)
     {
        la[i] = a[i + l];
     }

     for(long i = 0; i < n2; i++)
     {
        ra[i] = a[m + i + 1];
     }

     long i = 0, j = 0, k = 0;

     for(k = l; i < n1 && j < n2; k++)
     {
        if(la[i] > ra[j])
        {
            cnt += n1 - i;
            a[k] = ra[j++];
        }
        else {
            a[k] = la[i++];
        }
     }

     while(i < n1)
     {
        a[k++]=la[i++];
     }

     while(j < n2)
     {
        a[k++]=ra[j++];
     }
}

void merge_sort(long l, long r)
{
    if(l == r)
    {
        return;
    }

    long m = l + (r - l) / 2;

    merge_sort(l, m);
    merge_sort(m + 1, r);
    _merge(l, m, r);
}

int main()
{
    long n;

    while(1) {
        scanf("%ld", &n);

        if(n == 0)
        {
            break;
        }

        for(long i = 0; i < n; i++)
        {
            scanf("%ld", &a[i]);
        }

        cnt = 0;
        merge_sort(0, n-1);

        printf("%ld\n", cnt);
    }

    return(0);
}
