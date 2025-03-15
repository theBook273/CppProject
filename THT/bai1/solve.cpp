#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, x1, y1, x2, y2, defaultRes1, defaultRes2;

        defaultRes1 = defaultRes2 = 4;

        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        if (x1 - 1 <= 0) {
            defaultRes1--;
        }

        if (y1 - 1 <= 0) {
            defaultRes1--;
        }

        if (x1 + 1 > n) {
            defaultRes1--;
        }

        if (y1 + 1 > m) {
            defaultRes1--;
        }

        if (x2 - 1 <= 0) {
            defaultRes2--;
        }

        if (y2 - 1 <= 0) {
            defaultRes2--;
        }

        if (x2 + 1 > n) {
            defaultRes2--;
        }

        if (y2 + 1 > m) {
            defaultRes2--;
        }

        cout << min(defaultRes1, defaultRes2) << endl;
    }
    return 0;
}