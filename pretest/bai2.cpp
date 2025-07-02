#include <bits/stdc++.h>
#define long long long long

using namespace std;

const long long maxn = 2 * 1e5 + 258;

long long a[maxn], b[maxn], n;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (long long i = 0; i < n; i++) {
            cin >> b[i];
        }

        long long margin = 1e9, need = 0, pos = -1;
        bool reject = 0;

        for (long long i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                if (pos != -1) {
                    reject = 1;
                    continue;
                }
                pos = i;
                need = b[i] - a[i];
            } else {
                margin = min(margin, a[i] - b[i]);
            }
        }

        if (reject || need > margin) {
            cout << "NO" << endl;
        } else
            cout << "YES" << endl;
    }
}
