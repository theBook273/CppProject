#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[1000001];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int res = 1e9;

        for (int i = 1; i < n; i++) {
            int tong = 0;
            int now = a[i];
            for (int j = i + 1; j <= n; j++) {
                if (a[j] - now != k) {
                    tong++;
                }
                now += k;
            }
            now = a[i];
            for (int j = i - 1; j >= 1; j--) {
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
