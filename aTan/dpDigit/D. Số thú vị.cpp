#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9;

string l, r;

int dp[105][2];

int dfs(string &s, int pos, bool tight) {
  if (pos == (int)s.size()) {
    return 1;
  }

  int &res = dp[pos][tight];
  if (res != -1) {
    return res;
  }

  res = 0;

  int lim = tight ? s[pos] - '0' : 9;

  for (int d = (pos % 2 == 0) ? 1 : 0; d <= lim; d += 2) {
    bool nt = tight & (d == lim);
    res = ((res % MOD) + (dfs(s, pos + 1, nt)) % MOD) % MOD;
  }

  return res;
}

bool check(string &s) {
  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0 && (s[i] - '0') % 2 == 0) {
      return 0;
    }
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> l >> r;

  memset(dp, -1, sizeof(dp));
  int right = dfs(r, 0, 1);

  memset(dp, -1, sizeof(dp));
  int left = dfs(l, 0, 1);

  cout << ((right - left + check(l)) % MOD + MOD) % MOD;
}
