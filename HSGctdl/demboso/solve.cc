#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("Demboso.inp", "r", stdin);
  freopen("Demboso.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> dp(n + 1, 1);

  for (int j = 2; j <= k; j++) {
    vector<int> temp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (dp[i] != 0) {
        for (int mul = i; mul <= n; mul += i) {
          temp[mul] = (temp[mul] + dp[i]) % MOD;
        }
      }
    }
    dp.swap(temp);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[i]) % MOD;
  }
  cout << ans << "\n";
}
