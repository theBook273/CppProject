#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long cal(long long x, long long xo, long long r) { return sqrt((r * r) - (x - xo) * (x - xo)); }

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        vector<long long> a(n), r(n);

        for (auto &i : a) cin >> i;
        for (auto &i : r) cin >> i;

        map<long long, long long> tong;

        for (long long i = 0; i < n; ++i) {
            long long aa = a[i];
            long long rr = r[i];
            for (long long x = aa - rr; x <= aa + rr; ++x) {
                tong[x] = max(tong[x], 2 * cal(x, aa, rr) + 1);
            }
        }

        long long res = 0;

        for (auto i : tong) {
            res += i.second;
        }

        cout << res << endl;
    }
}
