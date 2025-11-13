#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }

  vector<int> dp(n);
  int res = a[0];
  dp[0] = a[0];
  for (int i = 1; i < n; i++) {
    dp[i] = max({
        a[i],
        a[i] + dp[i - 1],
        a[i] + a[i - 1],
    });
    res = max(res, dp[i]);
  }
  cout << res;
}
