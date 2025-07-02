#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, dem[2] = {0, 0};
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            char temp;
            cin >> temp;
            dem[temp - '0']++;
        }

        int good = 0;
        while (good < k) {
            if (dem[0] > dem[1]) {
                dem[0] -= 2;
                good++;
            } else {
                dem[1] -= 2;
                good++;
            }
        }

        if (dem[0] == dem[1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}