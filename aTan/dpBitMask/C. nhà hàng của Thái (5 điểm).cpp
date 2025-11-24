#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;
int n, m, k;

string bin(int x) {
  string s;
  for (int i = m - 1; i >= 0; i--) {
    char ins = '0';
    if ((x >> i) & 1) {
      ins = '1';
    }
    s.push_back(ins);
  }
  return s;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  int full = (1 << n);
  vector<vector<int>> dp(n + 1, vector<int>(full + 1, 0));
  for (int i = 0; i < n; i++) {
    dp[i][(1 << i)] = a[i];
  }

  vector<vector<int>> bonus(n + 1, vector<int>(n + 1, 0));
  for (int u, v, c, i = 0; i < k; i++) {
    cin >> u >> v >> c;
    u--, v--;
    bonus[u][v] += c;
  }

  for (int mask = 0; mask < full; mask++) {
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }
    for (int i : pos) {
      int pmask = mask ^ (1 << i);
      for (int j : pos) {
        if (i != j) {
          dp[i][mask] = max(dp[i][mask], dp[j][pmask] + a[i] + bonus[j][i]);
        }
      }
    }
  }

  int res = -oo;
  for (int mask = 0; mask < full; mask++) {
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }
    if ((int)pos.size() == m)
      for (int i : pos) {
        res = max(res, dp[i][mask]);
      }
  }

  cout << res;
}
