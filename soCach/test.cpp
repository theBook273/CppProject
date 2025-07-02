#include <bits/stdc++.h>

using namespace std;

long long bin[10000];
long long n;

void solve(long long current)
{
    for (long long i = 0; i <= 1; i++)
    {
        bin[current] = i;
        if (current == n - 1)
        {
            for (long long j = 0; j < n; j++)
            {
                cout << bin[j];
            }
            cout << endl;
        }
        else
            solve(current + 1);
    }
}

long long main()
{
    cin >> n;
    solve(0);
}
