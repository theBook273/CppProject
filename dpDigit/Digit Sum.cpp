#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

string l, r;
int d;
int dp[10005][105][2];

int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }

int dfs(string &s, int pos, int sum, bool tight) {
  if (pos == (int)s.size()) {
    return sum % d == 0;
  }

  int &res = dp[pos][sum][tight];
  if (res != -1) {
    return res;
  }

  res = 0;
  int lim = tight ? s[pos] - '0' : 9;

  for (int i = 0; i <= lim; i++) {
    bool nt = tight & (i == lim);
    res = add(res, dfs(s, pos + 1, (sum + i) % d, nt));
  }

  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> r >> d;
  l = "0";

  memset(dp, -1, sizeof(dp));
  int right = dfs(r, 0, 0, 1);

  memset(dp, -1, sizeof(dp));
  int left = dfs(l, 0, 0, 1);

  cout << ((right - left) % MOD + MOD) % MOD;
}
