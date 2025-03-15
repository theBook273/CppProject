#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int a[n];

        for (auto &i : a) cin >> i;

        sort(a, a + n);

        int l = 0;
        int temp = a[l], res = 0;
        for (int r = 1; r < n; r++) {
            temp += a[r];

            if (abs(a[r] - a[l]) > 1) {
                while (a[r] - a[l] > 1) temp -= a[l++];
            }

            if (temp > m) {
                while (temp > m) temp -= a[l++];
            }

            res = max(temp, res);
        }
        if (temp <= m) res = max(temp, res);
        cout << res << endl;
    }
}