#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;

  vector<int> l(n + 1), r(n + 1), dp(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> l[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }

  dp[0] = 0;
  dp[1] = l[1];
  for (int i = 2; i <= n; i++) {
    dp[i] = min(dp[i - 1] + l[i], dp[i - 2] + r[i - 1]);
  }
  cout << dp[n];
}
