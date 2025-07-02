#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

double avgg(pair<ll, long long> a[], long long n) {
    double tong = 0;
    for (ll i = 0; i < n; i++) {
        tong += a[i].first;
    }
    return tong;
}

bool comp(pair<ll, long long> a, pair<long long, long long> b) { return a.second < b.second; }

signed main() {
    ll n, avg;

    cin >> n >> avg;

    pair<ll, long long> a[n];

    for (auto &i : a) {
        cin >> i.first >> i.second;
    }

    sort(a, a + n, comp);

    ll tong = avgg(a, n), res = 0;

    for (ll i = 0; i < n; i++) {
        if (a[i].first == 10) continue;
        tong++;
        res += a[i].second;
        if (tong / n == avg) {
            break;
        }
    }
    if (tong / n < avg) {
        cout << "khong the";
        return 0;
    }
    // cout << res;
    for (auto i : a) {
        cout << i.first << " " << i.second << endl;
    }
}
