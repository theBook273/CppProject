#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5;

int n, m, k, start, timer = 0, tplt = 0, res = 0;
vector<pair<int, int>> edge;
vector<int> dp, id, low, scc, supMo, game, comp[N + 5], adj[N + 5];
vector<bool> outSt, vis;
stack<int> st;

void tarjan(int u) {
  id[u] = low[u] = ++timer;
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
      st.pop();
      outSt[v] = 1;
      scc[v] = tplt;
    } while (v != u);
  }
}

void dfs(int u) {
  if (game[u] == 1) {
    dp[u] = supMo[u];
  } else {
    dp[u] = 0;
  }
  vis[u] = 1;
  for (int v : comp[u]) {
    if (!vis[v]) {
      dfs(v);
    }
    if (dp[v] != 0) {
      dp[u] = max(dp[u], dp[v] + supMo[u]);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  id.resize(n + 1, 0);
  low.resize(n + 1, 0);
  outSt.resize(n + 1, 0);
  scc.resize(n + 1, 0);
  supMo.resize(n + 1, 0);
  vis.resize(n + 1, 0);
  game.resize(n + 1, 0);
  dp.resize(n + 1, 0);

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

  for (auto [u, v] : edge) {
    u = scc[u];
    v = scc[v];
    if (u != v) {
      comp[u].push_back(v);
    }
  }

  for (int x, i = 1; i <= n; i++) {
    cin >> x;
    supMo[scc[i]] += x;
  }

  cin >> start;
  start = scc[start];

  cin >> k;
  for (int x, i = 1; i <= k; i++) {
    cin >> x;
    game[scc[x]] = 1;
  }

  dfs(start);

  cout << dp[start];
}
