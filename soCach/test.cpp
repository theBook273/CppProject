#include <bits/stdc++.h>

using namespace std;

int bin[10000];
int n;

void solve(int current)
{
    for (int i = 0; i <= 1; i++)
    {
        bin[current] = i;
        if (current == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << bin[j];
            }
            cout << endl;
        }
        else
            solve(current + 1);
    }
}

int main()
{
    cin >> n;
    solve(0);
}