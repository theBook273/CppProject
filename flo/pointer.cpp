#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        long long a[n];

        for (auto &i : a) cin >> i;

        sort(a, a + n);

        long long l = 0;
        long long temp = a[l], res = 0;
        for (long long r = 1; r < n; r++) {
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
