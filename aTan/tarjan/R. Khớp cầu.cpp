#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

int n, m, tplt = 0, timer = 0, khop = 0, cau = 0;
vector<int> low, id, scc;
vector<pair<int, int>> edge, adj[N + 5];
stack<int> st;

void tarjan(int u, int lastEd) {
  low[u] = id[u] = ++timer;
  st.push(u);
  int vung = (lastEd != -1);
  for (auto [v, ed] : adj[u]) {
    if (ed == lastEd) {
      continue;
    }

    if (id[v]) {
      low[u] = min(low[u], id[v]);
    }

    else {
      tarjan(v, ed);
      low[u] = min(low[u], low[v]);
      if (low[v] >= id[u]) {
        vung++;
      }
    }
  }

  if (vung > 1) {
    khop++;
  }

  if (id[u] == low[u]) {
    tplt++;
    int v;
    do {
      v = st.top();
      st.pop();
      scc[v] = tplt;
    } while (v != u);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  id.resize(n + 1, 0);
  low.resize(n + 1, 0);
  scc.resize(n + 1, 0);

  for (int u, v, i = 0; i < m; i++) {
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

  for (auto [u, v] : edge) {
    u = scc[u];
    v = scc[v];
    if (u != v) {
      cau++;
    }
  }

  cout << khop << " " << cau;
}
