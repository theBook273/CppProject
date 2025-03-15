#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("FENCES.INP", "r", stdin);
    freopen("FENCES.OUT", "w", stdout);

    int n, m;

    cin >> m >> n;

    cout << (m - 1 + 2) * n + (n - 1 + 2) * m;
}