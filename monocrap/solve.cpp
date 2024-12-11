#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, m, a[1000];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n, greater<int>());

        int res = 1e9;

        for (int i = 0; i < n; i++) {
            m -= a[i];
            if (m >= 0) res = min(res, m);
        }

        cout << res << endl;
    }
}