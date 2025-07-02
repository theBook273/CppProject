#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long tong, n, x, y, a[200025];

long long calc(long long a[], long long x) {
    long long res = 0;
    long long j = 0;

    for (long long i = n - 1; i >= 0; --i) {
        while (j < n && tong - a[j] - a[i] >= x) {
            ++j;
        }
        res += (n - j);
    }

    for (long long i = 0; i < n; ++i) {
        if (tong - a[i] - a[i] < x) {
            res--;
        }
    }

    return res / 2;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    long long t;
    cin >> t;

    while (t--) {
        cin >> n >> x >> y;

        tong = 0;

        memset(a, 0, sizeof(a));

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            tong += a[i];
        }

        sort(a, a + n);

        cout << calc(a, y + 1) - calc(a, x) << endl;
    }
}
