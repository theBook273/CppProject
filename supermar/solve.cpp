#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll x, m, n;
vector<ll> a;

bool check(long long dis) {
    ll broken = 0, k = dis;
    for (long long i = 1; i < a.size(); i++) {
        if (a[i] < k)
            broken++;
        else
            k = a[i] + dis;
    }
    return broken <= m;
}

signed main() {
    // freopen("supermar.inp", "r", stdin);
    // freopen("supermar.out", "w", stdout);
    cin >> x >> n >> m;
    a.push_back(0);
    for (long long i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        a.push_back(temp);
    }
    a.push_back(x);

    sort(a.begin(), a.end());

    long long l = 1, r = 1e9;

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
}
