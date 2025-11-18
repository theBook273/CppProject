#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 2025;
int n, a[N], dp[N][N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  dp[1][k] = -1e18;
  for (int i = 2; i <= n; i++) {
    dp[i][k] = max(dp[i - 1][k], a[i] - a[i - 1]);
  }
  for (int i = 2; i <= n; i++)
    for (int j = k - 1; j >= 0; j--)
      dp[i][k] = max({
          dp[i - 1][k],
          abs(a[i] - a[j - 1]),
      })
}
