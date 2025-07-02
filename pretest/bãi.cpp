#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long a[225];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long check = 0;

        for (long long i = 0; i < n - 1; i++) {
            if (2 * a[i] > a[i + 1] && 2 * a[i + 1] > a[i]) {
                check = 1;
            }
        }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
