#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> dp(n, 1);
  for (auto &i : a) {
    cin >> i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (a[i] > a[j]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
  }

  // for (auto i : dp) {
  //   cout << i << " ";
  // }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, dp[i]);
  }
  cout << res;
}
