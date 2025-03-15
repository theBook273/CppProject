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

        int a[200006];

        int b[n], c[n];

        for (auto &i : b) cin >> i;
        for (auto &i : c) cin >> i;

        int id = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c[i]; j++) {
                a[id++] = b[i];
            }
        }
        sort(a, a + id);

        int l = 0;
        int temp = a[l], res = 0;
        for (int r = 1; r < id; r++) {
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