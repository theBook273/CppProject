#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("MARBLE.INP", "r", stdin);
    freopen("MARBLE.OUT", "w", stdout);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    cin >> m;
    vector<int> b(m);
    for (auto &i : b) cin >> i;

    int l = 0, r = m - 1;
    while (l < n && a[l] <= a[l + 1]) l++;
    while (r >= 0 && b[r] >= b[r - 1]) r--;

    int res = 0;

    for (int i = 0; i <= l; ++i) {
        while (a[i] > b[r] && r < m) r++;
        if (r >= m) break;
        res = max(res, i + m - r + 1);
    }
    cout << res << endl;
}