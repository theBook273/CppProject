#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;

vector<int> val(N + 1, 0), adj[N + 5];
vector<vector<int>> dp(N + 1, vector<int>(2, 0));
int n, c;

void dfs(int u, int p) {
  for (auto v : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
  }

  int temp = val[u];
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }

    temp += max(dp[v][0], dp[v][1] - 2 * c);
  }

  dp[u][1] = max(0LL, temp);

  temp = 0;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }

    temp += max({0LL, dp[v][1], dp[v][0]});
  }

  dp[u][0] = max(0LL, temp);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("ROBIN.INP", "r", stdin);
  freopen("ROBIN.OUT", "w", stdout);

  cin >> n >> c;

  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, -1);

  cout << max(dp[1][0], dp[1][1]);
}
