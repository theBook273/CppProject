#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);

  for (auto &i : a) {
    cin >> i;
  }

  vector<int> dp(n, 0);

  dp[0] = a[0];

  for (int i = 1; i < n; i++) {
    dp[i] = a[i];
    dp[i] += max({a[i - 1], dp[i - 1], 0LL});
  }

  cout << *max_element(dp.begin(), dp.end());
}
