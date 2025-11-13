#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100005;
int dp[MAXN];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("Demboso.inp", "r", stdin);
  // freopen("Demboso.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
  }

  for (int j = 2; j <= k; j++) {
    vector<int> temp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      if (dp[i] == 0)
        continue;
      for (int mul = i; mul <= n; mul += i) {
        temp[mul] = (temp[mul] + dp[i]) % MOD;
      }
    }
    for (int i = 1; i <= n; ++i) {
      dp[i] = temp[i];
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + dp[i]) % MOD;
  }
  cout << ans << '\n';
}
