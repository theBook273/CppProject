#include <bits/stdc++.h>

using namespace std;
long long n;
long long a[200007], b[200007];

bool solve(long long x) {
    long long cnt = 0;

    for (long long i = 0; i < n; i++) {
        if (cnt <= b[i] && x - cnt - 1 <= a[i]) {
            cnt++;
        }
    }
    return cnt >= x;
}

long long main() {
    cin >> n;

    long long l = 1, r = n, res = 0;

    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++) cin >> b[i];

    while (l <= r) {
        long long m = (l + r) / 2;
        if (solve(m)) {
            res = m;
            l = m + 1;
        } else
            r = m - 1;
    }

    cout << res;
}
