#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> dp(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = a[i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        dp[i] = max({dp[i], a[i] + dp[j]});
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}
