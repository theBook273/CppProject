#include <bits/stdc++.h>

using namespace std;

signed main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k, dem[2] = {0, 0};
        cin >> n >> k;
        for (long long i = 0; i < n; ++i) {
            char temp;
            cin >> temp;
            dem[temp - '0']++;
        }

        long long good = 0;
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
