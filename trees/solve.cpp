#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;

        vector<pair<long long, long long>> event;
        for (long long i = 0; i < n; i++) {
            event.push_back({a[i], 1});
            event.push_back({b[i], 2});
        }

        sort(event.begin(), event.end());

        long long bad = 0, amount = n, res = 0;

        for (long long i = 0; i < 2 * n;) {
            long long current = event[i].first;

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
