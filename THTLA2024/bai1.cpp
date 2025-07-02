#include <bits/stdc++.h>

using namespace std;

signed main() {
    freopen("MAX.INP", "r", stdin);
    freopen("MAX.OUT", "w", stdout);
    int n;
    cin >> n;
    int a[n], b[n];
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= i; --j) {
            if (j >= i && b[j] >= a[i]) {
                res = max(res, j - i);
            }
        }
    }
    cout << res << endl;
}