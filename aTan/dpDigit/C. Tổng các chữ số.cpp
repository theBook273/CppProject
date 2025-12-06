#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

string l, r;
int dp[105][905][2];

int dem(string &s, int pos, int sum, bool tight) {
  if (pos == (int)s.size()) {
    return sum;
  }

  int &res = dp[pos][sum][tight];
  if (res != -1) {
    return res;
  }

  res = 0;

  int lim = tight ? (s[pos] - '0') : 9;

  for (int d = 0; d <= lim; d++) {
    bool nt = (tight) & (d == lim);
    res = (res + dem(s, pos + 1, sum + d, nt)) % MOD;
  }

  return res;
}

int g(string &s) {
  int res = 0;
  for (auto &i : s) {
    res += i - '0';
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> l >> r;

  memset(dp, -1, sizeof(dp));
  int right = dem(r, 0, 0, 1);

  memset(dp, -1, sizeof(dp));
  int left = dem(l, 0, 0, 1);

  cout << ((right - left + g(l)) % MOD + MOD) % MOD;
}
