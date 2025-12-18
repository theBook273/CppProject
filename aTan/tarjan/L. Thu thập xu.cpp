#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
int n, m, res = 0, timer = 0, tplt = 0;
vector<int> low, id, supCoin, coin, scc, dp, comp[N + 5], adj[N + 5];
vector<pair<int, int>> edge;
vector<bool> vis, outSt;
stack<int> st;

void dfs(int u) {
  dp[u] = supCoin[u];
  vis[u] = 1;
  for (int v : comp[u]) {
    if (!vis[v]) {
      dfs(v);
    }
    dp[u] = max(dp[u], dp[v] + supCoin[u]);
  }
  res = max(res, dp[u]);
}

void tarjan(int u) {
  low[u] = id[u] = ++timer;
  st.push(u);
  for (int v : adj[u]) {
    if (!outSt[v]) {
      if (!id[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], low[v]);
      }
    }
  }

  if (low[u] == id[u]) {
    int v;
    tplt++;
    do {
      v = st.top();
      outSt[v] = 1;
      scc[v] = tplt;
      st.pop();
    } while (v != u);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  dp.resize(n + 1, 0);
  vis.resize(n + 1, 0);
  low.resize(n + 1, 0);
  id.resize(n + 1, 0);
  scc.resize(n + 1, 0);
  coin.resize(n + 1, 0);
  supCoin.resize(n + 1, 0);
  outSt.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> coin[i];
  }

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    edge.push_back({u, v});
  }

  for (int i = 1; i <= n; i++) {
    if (!id[i]) {
      tarjan(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    int x = scc[i];
    supCoin[x] += coin[i];
  }

  for (auto [u, v] : edge) {
    u = scc[u];
    v = scc[v];
    if (u != v) {
      comp[u].push_back(v);
    }
  }

  for (int i = 1; i <= tplt; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  cout << res;
}
