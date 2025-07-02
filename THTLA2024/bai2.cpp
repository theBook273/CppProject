#include <bits/stdc++.h>

using namespace std;
long long n, k;
long long a[220];

bool check(long long dis) {
    long long cnt = 0;
    long long current = 0;
    while (current < n) {
        cnt++;
        long long target = a[current] + dis;
        long long j = upper_bound(a + current, a + n, target) - a - 1;
        current = upper_bound(a + j, a + n, a[j] + dis) - a;
    }
    return cnt <= k;
}

signed main() {
    ifstream fin("BUS.INP");
    ofstream fout("BUS.OUT");

    cin >> n >> k;

    for (long long i = 0; i < n; ++i) cin >> a[i];

    long long l = 0, r = a[n - 1] - a[0] + 1, res = r;

    while (l <= r) {
        long long m = (l + r) / 2;
        if (check(m)) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << res << endl;
}
