#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll check = 0, tong = 0, minn = 1e9;
vector<ll> v;

signed main() {
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll temp;
            cin >> temp;
            if (temp < 0) check++;
            minn = min(minn, abs(temp));
            tong += abs(temp);
        }
    }

    if (check % 2 != 0) {
        tong -= 2 * minn;
    }

    cout << tong;
}