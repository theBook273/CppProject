#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    if (k <= (n / 2)) {
        cout << 2 * k << endl;
    } else {
        int lim1 = int(n / 2);

        if (n % 2 == 0) {
            if ((k - lim1 - 1) * 4 + 3 <= n) {
                cout << (k - lim1 - 1) * 4 + 3 << endl;
            } else {
                if (k == n) {
                    cout << 9;
                } else if (k == n - 2) {
                    cout << 1;
                } else {
                    cout << n - 3;
                }
                cout << endl;
            }
        } else {
            if ((k - lim1 - 1) * 4 + 1 <= n) {
                cout << (k - lim1 - 1) * 4 + 1 << endl;
            }
        }
    }
}