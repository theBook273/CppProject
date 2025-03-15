#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<char, ll> a[100000];
ll res = 1e9 + 9;

signed main() {
    ll n;

    cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    for (ll i = 0; i < n; i++) {
        ll dem = 0;
        for (ll j = 0; j < n; j++) {
            if (a[j].first == 'L' && a[j].second < a[i].second) {
                dem++;
            }

            if (a[j].first == 'G' && a[j].second > a[i].second) {
                dem++;
            }
        }
        res = min(res, dem);
    }

    cout << res;
}