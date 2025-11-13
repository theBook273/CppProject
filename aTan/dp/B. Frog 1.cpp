#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> rock(n);
  for (auto &i : rock) {
    cin >> i;
  }

  vector<int> dp(n);
  dp[0] = 0;
  dp[1] = abs(rock[1] - rock[0]);

  for (int i = 2; i < n; i++) {
    dp[i] = min(abs(rock[i] - rock[i - 1]) + dp[i - 1],
                abs(rock[i] - rock[i - 2]) + dp[i - 2]);
  }

  cout << dp[n - 1];
}
