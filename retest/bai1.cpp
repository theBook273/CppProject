#include <bits/stdc++.h>
#define long long long long

using namespace std;
long long n, a[900009], m, res;

void bin(long long x) {
    long long l = 1, r = n;
    while (l <= r) {
        long long mid = (l + r) / 2;
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

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;

    sort(a, a + n + 1);

    while (m--) {
        long long x;
        cin >> x;
        bin(x);
        cout << res << "\n";
        res = 0;
    }
}
