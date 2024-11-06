#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, q, a[1000000];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int b;
        cin >> b;

        int res = lower_bound(a, a + n, b) - a;

        if (res == n)
            cout << -1 << "\n";
        else
            cout << res << "\n";
    }
}
