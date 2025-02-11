#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[225];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int check = 0;

        for (int i = 0; i < n - 1; i++) {
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