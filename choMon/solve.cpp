#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[10000];
pair<ll, ll> dp[10000];
ll n, deChon;

signed main() {
    long long t;
    cin >> t;
    while (t--) {
        cin >> n;
        deChon = n / 2;

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            dp[i] = {a[i], 1};
        }

        for (long long i = 1; i < n; i++) {
            if (dp[i - 2].second + 1 <= deChon) {
                if (dp[i - 2].first + dp[i].first > dp[i - 1].first) {
                    dp[i] = {dp[i - 2].first + dp[i].first,
                             dp[i - 2].second + 1};
                } else {
                    dp[i] = {dp[i - 1].first, dp[i - 1].second};
                }
            } else {
                if (a[i - 2] + dp[i].first > dp[i - 1].first) {
                    dp[i] = {a[i - 2] + dp[i].first, dp[i].second + 1};
                } else {
                    dp[i] = {dp[i - 1].first, dp[i - 1].second};
                }
            }
        }

        // for (long long i = 0; i < n; i++) {
        //     cout << dp[i].first << " ";
        // }

        cout << dp[n - 1].first << endl;
    }
}
