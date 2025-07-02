#include <bits/stdc++.h>
#define long long long long

using namespace std;
long long n, a[1000000], b[1000000], tong = 0;
long long cong = 0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];

        tong += a[i];
    }

    long long ma = floor(double(tong) / n), mb = ceil(double(tong) / n);
    long long temp = n - (tong % n);

    for (long long i = 0; i < n; i++) {
        if (temp != 0) {
            b[i] = ma;
            temp--;
        } else
            b[i] = mb;
    }

    sort(a, a + n);

    for (long long i = 0; i < n; i++) {
        cong += abs(a[i] - b[i]);
    }

    cout << cong / 2;
}
