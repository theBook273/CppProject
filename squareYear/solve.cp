#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int sq = sqrt(n);
        if (n == 0)
            cout << 0 << " " << 0 << "\n";
        else if (sq * sq == n) {
            cout << 1 << " " << sq - 1 << "\n";
        } else
            cout << -1 << "\n";
    }
}