#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long t;

    cin >> t;

    while (t--) {
        long long n;

        cin >> n;

        pair<ll, ll> a[n];

        for (long long i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }

        sort(a, a + n);

        vector<long long> res;

        res.push_back(0);

        for (long long i = 0; i < n; i++) {
            long long len =
                upper_bound(res.begin(), res.end(), a[i].second) - res.begin();
            if (len == res.size())
                res.push_back(a[i].second);
            else
                res[len] = min(res[len], a[i].second);
        }
        cout << res.size() - 1 << endl;
    }
}
