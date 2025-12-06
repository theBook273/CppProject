#include <bits/stdc++.h>
#define int long long

using namespace std;

string l, r;
int dp[17][10000][2];

int dfs(string &s, int pos, int sum, bool tight) {
  if (pos == (int)s.size()) {
    return sum;
  }

  int &res = dp[pos][sum][tight];
  if (res != -1) {
    return res;
  }

  res = 0;
  int lim = tight ? s[pos] - '0' : 9;

  for (int i = 0; i <= lim; i++) {
    bool nt = tight & (i == lim);
    res += dfs(s, pos + 1, sum + i, nt);
  }

  return res;
}

int calc(string &s) {
  int res = 0;
  for (auto &i : s) {
    res += (i - '0');
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> l >> r;

  memset(dp, -1, sizeof(dp));
  int right = dfs(r, 0, 0, 1);

  memset(dp, -1, sizeof(dp));
  int left = dfs(l, 0, 0, 1);

  cout << right - left + calc(l);
}
