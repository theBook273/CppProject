#include <bits/stdc++.h>
#include <vector>
#define int long long

using namespace std;

const int oo = 1e18;
const int N = 700 + 5;

vector<vector<int>> offer(N, vector<int>(N, oo)), dp(N, vector<int>(N, oo)),
    pref(N, vector<int>(N, 0));

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pie.inp", "r", stdin);
  freopen("pie.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> offer[i][j];
    }
    sort(offer[i].begin() + 1, offer[i].begin() + m + 1);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] = pref[i][j - 1] + offer[i][j];
    }
  }

  for (int j = 1; j <= min(m, n); j++) {
    dp[1][j] = pref[1][j] + j * j;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j <= min((i - 1) * m, n); j++) {
      for (int k = 1; k <= m; k++) {
        if (j + k <= min(i * m, n)) {
          dp[i][j + k] = min(dp[i][j + k], dp[i - 1][j] + pref[i][k] + k * k);
        }
        if (j + k <= (i - 1) * m) {
          dp[i][j + k] = min(dp[i][j + k], dp[i - 1][j + k]);
        }
      }
    }
  }

  cout << dp[n][n];
}
