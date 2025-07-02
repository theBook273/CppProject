#include <bits/stdc++.h>

using namespace std;
vector<char> a[10000000];
long long tong = 0;
long long n, m;

void solve(long long i, long long j)
{
    a[i][j] = '.';

    if (a[i + 1][j] == '*')
    {
        solve(i + 1, j);
    }

    if (a[i][j + 1] == '*')
    {
        solve(i, j + 1);
    }

    if (a[i][j - 1] == '*')
    {
        solve(i, j - 1);
    }

    if (a[i - 1][j] == '*')
    {
        solve(i - 1, j);
    }
}

long long main()
{

    cin >> n >> m;

    for (long long i = 0; i < n + 2; i++)
    {
        for (long long j = 0; j < m + 2; j++)
        {
            a[i].push_back('.');
        }
    }

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            char temp;
            cin >> temp;
            a[i][j] = temp;
        }
    }

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            if (a[i][j] == '*')
            {
                tong++;
                solve(i, j);
            }
        }
    }

    cout << tong;
}
