#include <bits/stdc++.h>

using namespace std;

signed main() {
    freopen("MAX.INP", "r", stdin);
    freopen("MAX.OUT", "w", stdout);
    long long n;
    cin >> n;
    long long a[n], b[n];
    for (long long &i : a) cin >> i;
    for (long long &i : b) cin >> i;

    long long res = 0;

    for (long long i = 0; i < n; ++i) {
        for (long long j = n - 1; j >= i; --j) {
            if (j >= i && b[j] >= a[i]) {
                res = max(res, j - i);
            }
        }
    }
    cout << res << endl;
}
