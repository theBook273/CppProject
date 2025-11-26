#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int n, m;
int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    for (int k = 0; k < ai; k++) {
      int h;
      cin >> h;
      a[i][h - 1] = 1;
    }
  }
  int full = (1LL << m);
  vector<vector<int>> preCal(m + 1);
  for (int i = 0; i < full; i++) {
    preCal[__builtin_popcountll(i)].push_back(i);
  }
  vector<vector<int>> dp(n + 1, vector<int>(full, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (auto mask : preCal[i]) {
      vector<int> pos;
      for (int x = 0; x < m; x++) {
        if ((mask >> x) & 1) {
          pos.push_back(x);
        }
      }
      for (int j : pos) {
        if (a[i - 1][j] == 1) {
          dp[i][mask] = add(dp[i][mask], dp[i - 1][mask ^ (1LL << j)]);
        }
      }
    }
  }
  int ans = 0;
  for (auto mask : preCal[n]) {
    ans = add(ans, dp[n][mask]);
  }
  cout << ans;
}
