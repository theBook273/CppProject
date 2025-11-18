#include <bits/stdc++.h>

using namespace std;

vector<int> a, dp;
int n;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  a.resize(n);
  dp.resize(n, 0);
  for (auto &i : a) {
    cin >> i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (__gcd(a[i], a[j]) != 1) {
        dp[i] = dp[j] + 1;
      }
    }
  }

  cout << dp[n - 1];
}
