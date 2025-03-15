#include <bits/stdc++.h>
#define int long long

using namespace std;

main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int m, a, b, c, tong = 0;

        cin >> m >> a >> b >> c;

        tong += min(a, m);
        tong += min(b, m);
        tong += min(c, (m * 2 - tong));

        cout << tong << endl;
    }
}
