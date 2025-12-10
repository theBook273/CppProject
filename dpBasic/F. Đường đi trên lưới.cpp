#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<char>> a(n + 1, vector<char>(n + 1, '.'));
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  dp[1][1] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == '*') {
        dp[i][j] = 0;
        continue;
      }

      add(dp[i][j], dp[i - 1][j] + dp[i][j - 1]);
    }
  }

  cout << dp[n][n] % MOD;
}
