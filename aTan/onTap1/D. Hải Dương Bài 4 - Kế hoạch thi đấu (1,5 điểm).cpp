#include <bits/stdc++.h>

using namespace std;

int date[100005], dp[100005], point[100005];

signed main() {
  cin.tie()->sync_with_stdio(0);

  // freopen("BAI4.INP", "r", stdin);
  // freopen("BAI4.OUT", "w", stdout);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> date[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> point[i];
  }

  for (int i = 0; i < n; i++) {
    dp[i] = point[i];
    for (int j = 0; j < i; j++) {
      if (date[i] - date[j] >= k)
        dp[i] = max(dp[i], dp[j] + point[i]);
    }
    if (i > 0)
      dp[i] = max(dp[i], dp[i - 1]);
  }

  cout << *max_element(dp, dp + n);
}
