#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> c(n, vector<int>(n));
  for (auto &i : c) {
    for (auto &j : i) {
      cin >> j;
    }
  }

  int full = (1 << n) - 1;
  vector<vector<int>> dp(full + 1, vector<int>(n + 1, oo));

  for (int i = 0; i < n; i++) {
    dp[(1 << i)][i] = 0;
  }

  for (int mask = 0; mask <= full; mask++) {
    vector<int> pos;

    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }

    for (auto i : pos) {
      int pmask = mask ^ (1 << i);
      for (auto j : pos) {
        if (i != j) {
          dp[mask][i] = min(dp[mask][i], dp[pmask][j] + c[j][i]);
        }
      }
    }
  }

  int res = oo;
  for (int i = 0; i < n; i++) {
    res = min(res, dp[full][i]);
  }

  cout << res;
}
