#include <bits/stdc++.h>
#define long long long long

using namespace std;
long long n, q, a[1000000];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> q;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        long long b;
        cin >> b;

        long long res = lower_bound(a, a + n, b) - a;

        if (res == n)
            cout << -1 << "\n";
        else
            cout << res << "\n";
    }
}
