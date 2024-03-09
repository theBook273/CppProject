#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[1000000], maxF[1000000], maxG[1000000];
// a2 + (a1 + i1) + (a2 - i2)
signed main() {
    cin.tie(NULL)->sync_with_stdio(NULL);
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    maxF[1] = a[1] + 1;

    for (int i = 2; i <= n; i++) {
        maxF[i] = max(maxF[i - 1], a[i] + i);
    }

    maxG[n] = a[n] - n;

    for (int i = n - 1; i >= 0; i--) {
        maxG[i] = max(maxG[i + 1], a[i] - i);
    }

    int res = 0;

    for (int i = 2; i < n; i++) {
        res = max(res, maxF[i - 1] + maxG[i + 1] + a[i]);
    }
    cout << res;
}