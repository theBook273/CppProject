#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

int n, k;
vector<int> adj[N + 5], dp(N + 1, 0);

void dfs(int u, int p) {
  for (auto v : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
  }

  vector<int> node;

  for (auto v : adj[u]) {
    if (v == p) {
      continue;
    }

    node.push_back(dp[v]);
  }

  sort(node.begin(), node.end(), greater<>());

  for (int i = 0; i < (int)node.size(); i++) {
    dp[u] = max(dp[u], node[i] + 1 + i);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(k, -1);

  cout << dp[k];
}
