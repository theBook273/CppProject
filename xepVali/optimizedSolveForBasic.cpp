#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[100000], c[100000], dp[10000][10000];

long long main() {
    long long n, w;
    cin >> n >> w;

    for (long long i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }

    // for (long long i = 0; i <= n; i++) { dp[i][0] = 2;
    // }
    // for (long long j = 0; j <= w; j++) {
    //     dp[0][j] = 1;
    // }

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= w; j++) {
            // cout << i << " " << j << "|";
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[j]] + c[i]);
            }
        }
        // cout << endl;
    }
    // for (long long i = 0; i <= n; i++) {
    //     for (long long j = 0; j <= w; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][w];
}
