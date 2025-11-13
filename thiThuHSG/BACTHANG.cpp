#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

const int MOD = 998244353;

int add(int a, int b) { return (a % MOD) + (b % MOD); }

signed main() {
  cin.tie()->sync_with_stdio(0);

  // freopen("BACTHANG.inp", "r", stdin);
  // freopen("BACTHANG.out", "w", stdout);

  unordered_map<int, int> mp;
  int n, m;
  cin >> n >> m;
  for (int temp, i = 0; i < m; i++) {
    cin >> temp;
    mp[temp]++;
  }

  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[2] = 1;
  dp[3] = 1;

  for (int i = 2; i <= n; i++) {
    if (mp.count(i)) {
      dp[i] = 0;
    } else {
      dp[i] = add(dp[i - 2], dp[i - 3]);
      dp[i] %= MOD;
    }
  }

  cout << dp[n] % MOD;
}
