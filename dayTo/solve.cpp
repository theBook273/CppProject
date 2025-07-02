#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[1000001];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long t;

    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
        }

        long long res = 1e9;

        for (long long i = 1; i < n; i++) {
            long long tong = 0;
            long long now = a[i];
            for (long long j = i + 1; j <= n; j++) {
                if (a[j] - now != k) {
                    tong++;
                }
                now += k;
            }
            now = a[i];
            for (long long j = i - 1; j >= 1; j--) {
                if (now - a[j] != k) {
                    tong++;
                }
                now -= k;
            }
            res = min(res, tong);
        }
        cout << res << endl;
    }
}
