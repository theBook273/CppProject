#include <bits/stdc++.h>

using namespace std;

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NUlong long);
    // cout.tie(NUlong long);
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> b(n - 1), a;

        for (auto &i : b) cin >> i;

        a.push_back(b[0]);

        for (long long i = 1; i < n - 1; i++) {
            a.push_back(min(b[i - 1], b[i]));
        }

        a.push_back(b[n - 2]);

        for (auto &i : a) cout << i << " ";
        cout << endl;
    }
}
