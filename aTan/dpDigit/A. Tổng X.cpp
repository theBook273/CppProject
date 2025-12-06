#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

string l, r;
int x;
int dp[105][905][2];

int dem(string &s, int pos, int sum, bool tight) {
  if (sum > x) {
    return 0;
  }
  if (pos == (int)s.size()) {
    return (sum == x);
  }
  if (dp[pos][sum][tight] != -1) {
    return dp[pos][sum][tight];
  }

  int &res = dp[pos][sum][tight];
  res = 0;

  int lim = tight ? (s[pos] - '0') : 9;

  for (int d = 0; d <= lim; d++) {
    bool nt = (tight && (d == lim));
    res = (res + dem(s, pos + 1, sum + d, nt)) % MOD;
  }

  return res;
}

int g(string s) {
  int tong = 0;
  for (auto i : s) {
    tong += i - '0';
  }
  return tong == x;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> l >> r >> x;

  memset(dp, -1, sizeof(dp));
  int right = dem(r, 0, 0, 1);

  memset(dp, -1, sizeof(dp));
  int left = dem(l, 0, 0, 1);

  cout << ((right - left + g(l)) % MOD + MOD) % MOD;
}
