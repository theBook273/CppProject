#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e18;

int n, k;
vector<pair<int, int>> adj[MAXN];
vector<int> dp[MAXN];

void mergeDP(vector<int> &a, vector<int> &b, int w) {
  if (b.size() > a.size()) {
    swap(a, b);
  }

  vector<int> merge(a.size() + b.size() - 1, INF);

  for (int i = 1; i < a.size(); i++) {
    for (int j = 1; j < b.size(); j++) {
      merge[i + j] = min(merge[i + j], a[i] + b[j] + 2 * w * i * j);
    }
  }

  for (int i = 1; i < (int)a.size(); i++)
    merge[i] = min(merge[i], a[i]);

  a = merge;
}

void dfs(int u, int p) {
  bool isLeaf = 1;
  dp[u] = vector<int>(2, INF);
  dp[u][1] = 0;

  for (auto [v, w] : adj[u]) {
    if (v == p)
      continue;
    isLeaf = 0;
    dfs(v, u);
    mergeDP(dp[u], dp[v], w);
  }

  if (isLeaf) {
    dp[u][1] = 0;
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> k;
  for (int u, v, w, i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(1, 1);
  cout << dp[1][k];
}
