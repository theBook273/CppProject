#include <bits/stdc++.h>
#define long long long long

using namespace std;

const long long maxn = 5 * 1e4 + 8;

long long a[maxn];
long long n, k;

bool check(long long x, long long pizz) {
    long long temp1 = a[n - 1];

    temp1 += x;
    pizz -= x;

    for (long long i = n - 2; i >= 0; i--) {
        if (a[i] * 2 < temp1) {
            long long sub = ceil(temp1 / 2.0) - a[i];
            if (pizz - sub >= 0) {
                temp1 = a[i] + sub;
                pizz -= sub;
            } else {
                return 0;
            }
        } else
            return 1;
    }
    return 1;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (k--) {
        long long pizza;
        cin >> pizza;
        long long left = 0, right = pizza;
        long long res = a[n - 1];
        while (left <= right) {
            long long mid = (right + left) / 2;
            if (check(mid, pizza)) {
                res = mid + a[n - 1];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << res << " ";
    }
}
