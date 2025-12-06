#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

vector<int> dp(N + 1, 0), adj[N + 5];
int n, res = 0;

void dfs(int u, int p) {
  int max1, max2;
  max1 = max2 = 0;
  for (auto v : adj[u]) {
    if (p == v) {
      continue;
    }

    dfs(v, u);

    dp[u] = max(dp[u], dp[v] + 1);
    if (dp[v] + 1 > max1) {
      max2 = max1;
      max1 = dp[v] + 1;
    } else if (dp[v] + 1 > max2) {
      max2 = dp[v] + 1;
    }
  }

  res = max(res, max1 + max2);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, -1);

  cout << res;
}
