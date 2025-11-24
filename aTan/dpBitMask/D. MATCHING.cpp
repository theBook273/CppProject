#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

int n;

int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (auto &i : a) {
    for (int &j : i) {
      cin >> j;
    }
  }

  int full = (1 << n);
  vector<int> preCal[n + 1];
  for (int i = 0; i < full; i++) {
    preCal[__builtin_popcount(i)].push_back(i);
  }

  vector<vector<int>> dp(n + 1, vector<int>(full, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (auto mask : preCal[i]) {
      vector<int> pos;
      for (int x = 0; x < n; x++) {
        if ((mask >> x) & 1) {
          pos.push_back(x);
        }
      }
      for (int j : pos) {
        if (a[i - 1][j] == 1) {
          dp[i][mask] = add(dp[i][mask], dp[i - 1][mask ^ (1 << j)]);
        }
      }
    }
  }

  cout << dp[n][full - 1];
}
