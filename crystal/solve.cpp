#include <bits/stdc++.h>

using namespace std;

long long a[3] = {0, 0, 0};
long long x;

bool check() {
    if (a[0] < x) return 0;
    if (a[1] < x) return 0;
    if (a[2] < x) return 0;
    return 1;
}

long long minx(long long b) {
    long long res = 1e9;
    for (long long i = 0; i < 3; i++) {
        if (i == b) continue;
        res = min(res, a[i]);
    }
    return res;
}

signed main() {
    long long t;
    cin >> t;
    while (t--) {
        a[0] = a[1] = a[2] = 0;
        cin >> x;
        long long dem = 0;
        while (!check()) {
            for (long long i = 0; i < 3; i++) {
                a[i] = 2 * minx(i) + 1;
                if (a[i] > x) a[i] = x;
                // for (long long i = 0; i < 3; ++i) cout << a[i] << " ";
                // cout << "\n";
                dem++;
                if (check()) break;
            }
        }
        cout << dem << "\n";
    }
}
