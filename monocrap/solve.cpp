#include <bits/stdc++.h>
#define long long long long

using namespace std;
long long n, m, a[1000];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    long long t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n, greater<long long>());

        long long res = 1e9;

        for (long long i = 0; i < n; i++) {
            m -= a[i];
            if (m >= 0) res = min(res, m);
        }

        cout << res << endl;
    }
}
