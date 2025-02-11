#include <bits/stdc++.h>
#define int long long

using namespace std;

int tong, n, x, y, a[200025];

int calc(int a[], int x) {
    int res = 0;
    int j = 0;

    for (int i = n - 1; i >= 0; --i) {
        while (j < n && tong - a[j] - a[i] >= x) {
            ++j;
        }
        res += (n - j);
    }

    for (int i = 0; i < n; ++i) {
        if (tong - a[i] - a[i] < x) {
            res--;
        }
    }

    return res / 2;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> x >> y;

        tong = 0;

        memset(a, 0, sizeof(a));

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tong += a[i];
        }

        sort(a, a + n);

        cout << calc(a, y + 1) - calc(a, x) << endl;
    }
}