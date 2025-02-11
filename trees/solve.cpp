#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;

        vector<pair<int, int>> event;
        for (int i = 0; i < n; i++) {
            event.push_back({a[i], 1});
            event.push_back({b[i], 2});
        }

        sort(event.begin(), event.end());

        int bad = 0, amount = n, res = 0;

        for (int i = 0; i < 2 * n;) {
            int current = event[i].first;

            if (bad <= k) {
                res = max(res, amount * current);
            }
            while (i < 2 * n && event[i].first == current) {
                if (event[i].second == 1) {
                    bad++;
                } else {
                    bad--;
                    amount--;
                }
                ++i;
            }
        }

        cout << res << endl;
    }
}