#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

const int MOD = 1e9 + 7;

int n, res = 0;

int add(int a, int b) { return a % MOD + b % MOD; }

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  // int f1 = 1, f2 = 1, tong = 0;
  // res = add(f1, f2);
  //
  // for (int i = 2; i <= n; i++) {
  //   tong = f1 + f2;
  //   f1 = f2;
  //   f2 = tong;
  // }
  // cout << f2;

  vector<int> dp(n + 1);
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[n];
}
