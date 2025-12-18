#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

int n, m, timer = 0, tplt = 0, leaves = 0, dem = 0, res = 0;
vector<pair<int, int>> edge, adj[N + 5];
map<int, vector<int>> tree;
vector<bool> vis;
vector<int> scc, id, low, comp[N + 5];
stack<int> st;

void tarjan(int u, int lastEd) {
  id[u] = low[u] = ++timer;
  st.push(u);

  for (auto &[v, ed] : adj[u]) {
    if (ed != lastEd) {
      if (!id[v]) {
        tarjan(v, ed);
      }
      low[u] = min(low[u], low[v]);
    }
  }

  if (low[u] == id[u]) {
    int v;
    tplt++;
    do {
      v = st.top();
      scc[v] = tplt;
      st.pop();
    } while (v != u);
  }
}

void mark(int u) {
  vis[u] = 1;
  tree[dem].push_back(u);
  for (auto v : comp[u]) {
    if (!vis[v]) {
      mark(v);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("NOBRIDGE.INP", "r", stdin);
  // freopen("NOBRIDGE.OUT", "w", stdout);

  cin >> n >> m;

  scc.resize(n + 1, 0);
  vis.resize(n + 1, 0);
  low.resize(n + 1, 0);
  id.resize(n + 1, 0);

  for (int u, v, i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    edge.push_back({u, v});
  }

  for (int i = 1; i <= n; i++) {
    if (!id[i]) {
      tarjan(i, -1);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << i << " " << scc[i] << "\n";
  }

  for (auto [u, v] : edge) {
    u = scc[u];
    v = scc[v];
    if (u != v) {
      comp[u].push_back(v);
      comp[v].push_back(u);
    }
  }

  for (int i = 1; i <= tplt; i++) {
    if (!vis[i]) {
      dem++;
      mark(i);
    }
  }

  for (auto [id, node] : tree) {
    int temp = 0;
    for (auto x : node) {
      if (comp[x].size() == 1) {
        temp++;
      }
    }
    res += (temp + 1) / 2;
  }

  cout << res;
}
