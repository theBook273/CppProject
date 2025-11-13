#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  vector<bool> go(n + 1);
  for (int temp, i = 1; i <= n; i++) {
    cin >> temp;
    go[i] = temp;
  }

  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = (go[1] ? a : 0);
  for (int i = 2; i <= n; i++) {
    if (go[i] == 0) {
      dp[i] = dp[i - 1];
      continue;
    }
    int muaA = dp[i - 1] + a;
    int muaB = (i >= 7 ? dp[i - 7] : 0) + b;
    int muaC = (i >= 30 ? dp[i - 30] : 0) + c;
    dp[i] = min({muaA, muaB, muaC});
  }

  cout << dp[n];
}
