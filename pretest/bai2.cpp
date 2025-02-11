#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2 * 1e5 + 258;

int a[maxn], b[maxn], n;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int margin = 1e9, need = 0, pos = -1;
        bool reject = 0;

        for (int i = 0; i < n; i++) {
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