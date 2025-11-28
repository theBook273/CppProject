#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 606;
int n, m, pre[N][N], dp[N][N];
const int INF = 1e18;
vector<int> a[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("pie.inp", "r", stdin);
  freopen("pie.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
    sort(a[i].begin(), a[i].end());
  }
  for (int i = 1; i <= 2 * n; i++)
    for (int j = 1; j <= 2 * n; j++)
      dp[i][j] = INF;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      pre[i][j] = pre[i][j - 1] + a[i][j - 1];

  for (int i = 1; i <= min(n, m); i++)
    dp[1][i] = pre[1][i] + i * i;

  for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j <= min((i - 1) * m, n); j++) {
      for (int k = 1; k <= m; k++) {
        if (j + k <= min(i * m, n))
          dp[i][j + k] = min(dp[i][j + k], dp[i - 1][j] + pre[i][k] + k * k);
        if (j + k <= (i - 1) * m)
          dp[i][j + k] = min(dp[i][j + k], dp[i - 1][j + k]);
      }
    }
  }
  cout << dp[n][n] << endl;
}
