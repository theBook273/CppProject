#include <bits/stdc++.h>
#include <cstdio>
#define int long long

using namespace std;

int digit[30];
int dp[30][4];

int dfs(int pos, bool lim, int noZe) {
  if (noZe == 4) {
    return 0;
  }
  if (pos == 0) {
    return 1;
  }

  if (!lim && dp[pos][noZe] != -1) {
    return dp[pos][noZe];
  }

  int temp = 0;
  int upper_bound = lim ? digit[pos] : 9;
  for (int i = 0; i <= upper_bound; i++) {
    temp += dfs(pos - 1, lim && (i == upper_bound), noZe + (i != 0));
  }
  if (!lim) {
    dp[pos][noZe] = temp;
  }
  return temp;
}

int solve(int num) {
  int k = 0;
  memset(dp, -1, sizeof(dp));
  while (num) {
    digit[++k] = num % 10;
    num /= 10;
  }
  int c = dfs(k, 1, 0);
  return c;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << "\n";
  }
}
