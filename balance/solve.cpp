#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, a[1000000], b[1000000], tong = 0;
int cong = 0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        tong += a[i];
    }

    int ma = floor(double(tong) / n), mb = ceil(double(tong) / n);
    int temp = n - (tong % n);

    for (int i = 0; i < n; i++) {
        if (temp != 0) {
            b[i] = ma;
            temp--;
        } else
            b[i] = mb;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        cong += abs(a[i] - b[i]);
    }

    cout << cong / 2;
}