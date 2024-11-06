#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, a[900009], m, res;

void bin(int x) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            res = mid;
            l = mid + 1;
        } else if (a[mid] > x) {
            r = mid - 1;
        }
    }
}

main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;

    sort(a, a + n + 1);

    while (m--) {
        int x;
        cin >> x;
        bin(x);
        cout << res << "\n";
        res = 0;
    }
}
