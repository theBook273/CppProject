#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> dp(n + 1, 0);
  dp[0] = dp[1] = dp[2] = 1;
  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  }
  cout << dp[n];
}
