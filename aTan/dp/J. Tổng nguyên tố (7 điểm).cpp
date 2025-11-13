#include <bits/stdc++.h>

using namespace std;

vector<bool> prime(2 * 1e6 + 1, 1);

signed main() {
  cin.tie()->sync_with_stdio(0);

  prime[0] = prime[1] = 0;
  for (int i = 2; i <= 2 * 1e6; i++) {
    if (prime[i] == 1) {
      for (int j = 2; i * j <= 2 * 1e6; j++) {
        prime[i * j] = 0;
      }
    }
  }

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> dp(n, 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int res = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (prime[a[i] + a[j]]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res;
}
