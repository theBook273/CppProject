#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("SMGIFT.INP", "r", stdin);
  freopen("SMGIFT.OUT", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> dp(k + 1), newdp(k + 1);
  dp[0] = 0;
  int maxNow = 0;
  for (int i = 1; i <= n; ++i) {
    newdp[0] = maxNow;
    for (int j = 1; j <= k; ++j) {
      newdp[j] = dp[j - 1] + a[i];
      maxNow = max(maxNow, newdp[j]);
    }
    dp.swap(newdp);
  }
  cout << *max_element(dp.begin(), dp.end());
}
