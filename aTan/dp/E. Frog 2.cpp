#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> rock(n);
  for (auto &i : rock) {
    cin >> i;
  }

  vector<int> dp(n);
  dp[0] = 0;
  dp[1] = abs(rock[1] - rock[0]);

  for (int i = 2; i < n; i++) {
    int res = 1e9;
    for (int j = max(0, (i - k)); j < i; j++) {
      res = min(res, abs(rock[i] - rock[j]) + dp[j]);
    }
    dp[i] = res;
  }

  cout << dp[n - 1];
}
