#include <bits/stdc++.h>

using namespace std;

const int k = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("ODDEVEN.INP", "r", stdin);
    freopen("ODDEVEN.OUT", "w", stdout);

    long long x, y, n;

    cin >> x >> y >> n;

    vector<long long> a(n, 0);

    a[0] = x;
    a[1] = y;

    for (int i = 2; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            a[i] = (a[i - 1] + a[i - 2]) % k;
        }
        else
        {
            a[i] = abs(a[i - 1] - a[i - 2]) % k;
        }
    }

    cout << a[n - 1] << "\n";
}