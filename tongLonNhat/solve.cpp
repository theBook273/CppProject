#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long a[1000000], maxF[1000000], maxG[1000000];
// a2 + (a1 + i1) + (a2 - i2)
signed main() {
    cin.tie(NULL)->sync_with_stdio(NULL);
    long long n;

    cin >> n;

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }

    maxF[1] = a[1] + 1;

    for (long long i = 2; i <= n; i++) {
        maxF[i] = max(maxF[i - 1], a[i] + i);
    }

    maxG[n] = a[n] - n;

    for (long long i = n - 1; i >= 0; i--) {
        maxG[i] = max(maxG[i + 1], a[i] - i);
    }

    long long res = 0;

    for (long long i = 2; i < n; i++) {
        res = max(res, maxF[i - 1] + maxG[i + 1] + a[i]);
    }
    cout << res;
}
