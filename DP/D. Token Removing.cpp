#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int dp[1000][1000];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j > 0) {
        dp[i][j] = dp[i - 1][j - 1] % m;
      }

      if (j < i) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j] * (n - i + 1) * (j + 1)) % m;
      }
    }
  }

  int ans = 0;

  for (int j = 0; j <= n; j++) {
    ans += (dp[n][j] % m), ans %= m;
  }

  cout << ans << "\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
