#include <bits/stdc++.h>

using namespace std;

long long a[100000], tong, n, m;

bool check(long long x) {
    tong = 0;
    for (long long i = 0; i < n; i++) {
        tong += (a[i] / x);
    }
    return tong >= m;
}

int main() {
    cin >> n >> m;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long l = 1, r = 1e9, res = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << res << endl;
}