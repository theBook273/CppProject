#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long n, k, a[100009];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> k;

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long m = (1 + n) / 2;

    if (a[m] != 0) {
        for (long long i = m; i <= n; i++) {
            if (a[i] == 0) {
                m = i;
                break;
            }
        }
        for (long long i = m; i <= n; i++) {
            if (a[i] == 0) {
                m = i;
                break;
            }
        }
    }
}
