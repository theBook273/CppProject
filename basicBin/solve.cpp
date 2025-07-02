#include <bits/stdc++.h>
#define long long long long

using namespace std;
long long n, q, a[100008];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> q;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (q--) {
        long long b;
        cin >> b;

        long long l = 0, r = n - 1, check = -1;

        while (l <= r) {
            long long mid = (l + r) / 2;
            if (a[mid] >= b) {
                if (a[mid] == b) {
                    check = mid;
                }
                r = mid - 1;
            } else
                l = mid + 1;
        }
        cout << check << "\n";
    }
}
