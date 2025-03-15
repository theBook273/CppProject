#include <bits/stdc++.h>
#define int long long

using namespace std;

int cal(int x, int xo, int r) { return sqrt((r * r) - (x - xo) * (x - xo)); }

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), r(n);

        for (auto &i : a) cin >> i;
        for (auto &i : r) cin >> i;

        map<int, int> tong;

        for (int i = 0; i < n; ++i) {
            int aa = a[i];
            int rr = r[i];
            for (int x = aa - rr; x <= aa + rr; ++x) {
                tong[x] = max(tong[x], 2 * cal(x, aa, rr) + 1);
            }
        }

        int res = 0;

        for (auto i : tong) {
            res += i.second;
        }

        cout << res << endl;
    }
}