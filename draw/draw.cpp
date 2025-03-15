#include <bits/stdc++.h>

using namespace std;
vector<char> a[10000000];
int tong = 0;
int n, m;

void solve(int i, int j)
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

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            a[i].push_back('.');
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char temp;
            cin >> temp;
            a[i][j] = temp;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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