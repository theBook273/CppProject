#include <bits/stdc++.h>
#define int long long
#define maskof(x) (1 << (x))
#define on(x, i) (((x) >> (i)) & 1)

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> dp, a;
map<int, vector<int>> valid;

void add(int &a, int &b) {
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
  a.resize(n, vector<int>(n, 0));
  for (vector<int> &i : a) {
    for (int &j : i) {
      cin >> j;
    }
  }

  int full = maskof(n);
  for (int mask = 0; mask < full; mask++) {
    valid[__builtin_popcount(mask)].push_back(mask);
  }

  dp.resize(n + 1, vector<int>(full, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (auto mask : valid[i]) {
      vector<int> pos;
      for (int j = 0; j < n; j++) {
        if (on(mask, j)) {
          pos.push_back(j);
        }
      }
      for (int j : pos) {
        if (a[i - 1][j]) {
          int pmask = mask ^ (1 << j);
          add(dp[i][mask], dp[i - 1][pmask]);
        }
      }
    }
  }

  cout << dp[n][full - 1];
}
