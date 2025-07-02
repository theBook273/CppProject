#include <bits/stdc++.h>

using namespace std;

long long main() {
    freopen("MARBLE.INP", "r", stdin);
    freopen("MARBLE.OUT", "w", stdout);
    long long n, m;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a) cin >> i;

    cin >> m;
    vector<long long> b(m);
    for (auto &i : b) cin >> i;

    long long l = 0, r = m - 1;
    while (l < n && a[l] <= a[l + 1]) l++;
    while (r >= 0 && b[r] >= b[r - 1]) r--;

    long long res = 0;

    for (long long i = 0; i <= l; ++i) {
        while (a[i] > b[r] && r < m) r++;
        if (r >= m) break;
        res = max(res, i + m - r + 1);
    }
    cout << res << endl;
}
