#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
  vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
  vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((sum[i][j] - sum[i - 1][j]) % 2 == 0 && !dp[i - 1][j]) {
        dp[i][j] = 1;
      }
      if ((sum[i][j] - sum[i][j - 1]) % 2 == 0 && !dp[i][j - 1]) {
        dp[i][j] = 1;
      }
    }
  }

  if (dp[n][n]) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  while (q--) {
    solve();
  }
}
