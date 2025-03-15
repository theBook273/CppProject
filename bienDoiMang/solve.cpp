#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[9000000], changed[9000000];
map<ll, ll> mp;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;

    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (m--) {
        int l, r, u;
        cin >> l >> r >> u;

        changed[l - 1] += u;
        changed[r] -= u;
    }

    for (int i = 1; i < n; i++) {
        changed[i] = changed[i - 1] + changed[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] += changed[i];
    }

    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }

    while (q--) {
        ll x;
        cin >> x;
        cout << mp[x] << " ";
    }
}