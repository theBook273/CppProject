#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long h, m, a, b;

    cin >> h >> m >> a >> b;

    long long gioDoi = h - a;
    while (gioDoi > 23) {
        gioDoi -= 24;
    }
    while (gioDoi < 0) {
        gioDoi += 24;
    }

    gioDoi += b;
    while (gioDoi > 23) {
        gioDoi -= 24;
    }
    while (gioDoi < 0) {
        gioDoi += 24;
    }
    cout << gioDoi << " " << m;
}
