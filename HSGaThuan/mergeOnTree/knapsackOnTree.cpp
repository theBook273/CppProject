#include <bits/stdc++.h>
#include <climits>

using namespace std;

const int MAXN = 5 * 1e3 + 5;

vector<int> adj[MAXN];
int dp[MAXN][MAXN], sz[MAXN], a[MAXN];

void dfs(int u, int p) {
  dp[u][1] = a[u];
  sz[u] = 1;

  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    sz[u] += sz[v];
    for (int val = sz[u]; val > 1; val--) {
      for (int num = 1; num <= min(val - 1, sz[v]); num++) {
        dp[u][val] = max(dp[u][val], dp[u][val - num] + dp[v][num]);
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int u, v, i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  memset(dp, -0x3f, sizeof(dp));
  dfs(1, -1);

  for (int k = 1; k <= n; k++) {
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, dp[i][k]);
    }
    cout << ans << "\n";
  }
}
