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

        long long a[200006];

        long long b[n], c[n];

        for (auto &i : b) cin >> i;
        for (auto &i : c) cin >> i;

        long long id = 0;

        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < c[i]; j++) {
                a[id++] = b[i];
            }
        }
        sort(a, a + id);

        long long l = 0;
        long long temp = a[l], res = 0;
        for (long long r = 1; r < id; r++) {
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
