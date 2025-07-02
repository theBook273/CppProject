#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, w, a[101], c[101], dp[101][101];
map<ll, ll> mp;

signed main() {
    cin >> n >> w;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }

    for (long long j = 1; j <= w; j++) {
        for (long long i = 1; i <= n; i++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) {
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j - a[i]] + c[i],
                                             dp[i][j - a[i]] + c[i]));
            }
        }
    }
    long long dem = n;
    for (long long j = w; j >= 0; j--) {
        while (dem >= 0) {
            if (dp[dem - 1][j] != dp[dem][j]) {
                mp[dem]++;
                j = j - a[dem];
            }
            if (dp[dem][j] == dp[dem - 1][j]) {
                dem--;
            }
        }
    }
    cout << dp[n][w] << endl;
    for (auto i : mp) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
