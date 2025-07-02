#include <bits/stdc++.h>

using namespace std;

long long a[1000000];

long long tong = 0;

long long dp(long long l, long long r, long long k) {
    long long forPiu = 0, toCut, side = 0;

    while (k--) {
        long long tong1, tong2;

        tong1 = tong2 = 0;

        for (long long i = k - 1; i >= l; i--) {
            cout << a[i] << " ";
            tong1 += a[i];
        }
        cout << endl;

        for (long long i = k; i <= r; i++) {
            cout << a[i] << " ";
            tong2 += a[i];
        }
        cout << endl;

        if (forPiu < min(tong1, tong2)) {
            forPiu = min(tong1, tong2);
            toCut = k;
            tong1 == min(tong1, tong2) ? side = l : side = r;
        }
    }

    // cout << forPiu << " " << toCut << " " << side << endl;

    tong += forPiu;

    if (toCut > side) {
        return tong;
    }

    if (side == l)
        return dp(l, toCut, toCut);
    else
        return dp(toCut, r, r);
}

long long main() {
    long long n;

    cin >> n;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << dp(0, n - 1, n - 1);
}
