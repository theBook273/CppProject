#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int const MOD = (1e9 + 7);

int main()
{
    ll a[100000], b[100000], m, n;
    unsigned long long tichA = 1, tichB = 1;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tichA *= a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        tichB *= b[i];
    }

    cout << __gcd(tichA, tichB) % MOD;
}
