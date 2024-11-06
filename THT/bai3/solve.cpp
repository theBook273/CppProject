#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll res[200005];

ll tong(string n) {
    ll tong = 0;
    for (auto i : n) {
        tong += i - '0';
    }
    return tong;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    res[0] = 0;

    for (int i = 1; i <= 200000; i++) {
        res[i] = tong(to_string(i)) + res[i - 1];
    }

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        cout << res[n] << endl;
    }
}