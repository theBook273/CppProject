#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k, a[100009];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int m = (1 + n) / 2;

    if (a[m] != 0) {
        for (int i = m; i <= n; i++) {
            if (a[i] == 0) {
                m = i;
                break;
            }
        }
        for (int i = m; i <= n; i++) {
            if (a[i] == 0) {
                m = i;
                break;
            }
        }
    }
}