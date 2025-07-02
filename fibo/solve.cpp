#include <bits/stdc++.h>

using namespace std;

unsigned long long fibo[10000];

unsigned long long fiboA(long long i)
{
    if (fibo[i] != 0)
        return fibo[i];

    for (long long j = 2; j <= i; j++)
    {
        fibo[j] = fibo[j - 1] + fibo[j - 2];
    }

    return fibo[i];
}

long long main()
{
    long long n;
    cin >> n;

    fibo[0] = fibo[1] = 1;

    while (n--)
    {
        long long n;
        cin >> n;
        cout << fiboA(n) << endl;
    }
}
