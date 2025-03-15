#include <bits/stdc++.h>
#define int long long

using namespace std;

int h[10000], a[10000];

int n, res;

int check(int x) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += (abs(x - h[i]) * a[i]);
    }
    return tong;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        res = 1e18;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int l = 1, r = 1e9, mid;

        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(mid + 1) < check(mid))
                l = mid;
            else
                r = mid;
        }
        cout << min({check(l), check(mid), check(mid + 1), check(r)}) << endl;
    }
}