#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll frac(ll x) {
    if (x == 1) return 1;

    return x * frac(x - 1);
}

signed main() {
    ll t;

    cin >> t;

    while (t--) {
        ll n;

        cin >> n;

        cout << n - 1 << endl;
    }
}