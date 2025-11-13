#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e18;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF));
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    int bestPrev = -INF;
    for (int t = 1; t <= k; t++) {
      bestPrev = max(bestPrev, dp[i - 1][t]);
    }
    dp[i][0] = bestPrev;

    for (int j = 1; j <= k; j++) {
      if (dp[i - 1][j - 1] != -INF) {
        dp[i][j] = dp[i - 1][j - 1] + a[i];
      }
    }
  }

  int ans = -INF;
  for (int j = 0; j <= k; j++) {
    ans = max(ans, dp[n][j]);
  }
  cout << ans;
}
