#include <bits/stdc++.h>

using namespace std;

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NUint);
    // cout.tie(NUint);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n - 1), a;

        for (auto &i : b) cin >> i;

        a.push_back(b[0]);

        for (int i = 1; i < n - 1; i++) {
            a.push_back(min(b[i - 1], b[i]));
        }

        a.push_back(b[n - 2]);

        for (auto &i : a) cout << i << " ";
        cout << endl;
    }
}