#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll pre[1000001];

signed main() {
    int n, k;

    cin >> n >> k;

    char a[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[0] = '0';
    pre[1] = a[1] - 'a' + 1;

    for (int i = 2; i <= n; i++) {
        pre[i] = a[i] - 'a' + 1 + pre[i - 1];
    }

    while (k--) {
        ll l, r;

        cin >> l >> r;

        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}