#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 50000;
int n, m, k, l, timer = 0, tplt = 0, sA = 0, sB = 0, res = 0;
vector<int> id, low, scc, depth, cnta, cntb, pack[2], comp[N + 5];
vector<pair<int, int>> supEdge, edge, adj[N + 5];
vector<bool> serA, serB;
stack<int> st;

void tarjan(int u, int lastEd) {
  low[u] = id[u] = ++timer;
  st.push(u);
  for (auto [v, i] : adj[u]) {
    if (i == lastEd) {
      continue;
    }

    if (!id[v]) {
      tarjan(v, i);
    }
    low[u] = min(low[u], low[v]);
  }

  if (low[u] == id[u]) {
    int v;
    tplt++;
    do {
      v = st.top();
      st.pop();
      scc[v] = tplt;
    } while (v != u);
  }
}

void dfsCal(int u, int p) {
  cnta[u] = serA[u];
  cntb[u] = serB[u];
  for (auto v : comp[u]) {
    if (v == p) {
      continue;
    }
    depth[v] = depth[u] + 1;
    dfsCal(v, u);
    cnta[u] += cnta[v];
    cntb[u] += cntb[v];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k >> l;

  id.resize(n + 1, 0);
  low.resize(n + 1, 0);
  scc.resize(n + 1, 0);
  serA.resize(n + 1, 0);
  serB.resize(n + 1, 0);
  cnta.resize(n + 1, -1);
  cntb.resize(n + 1, -1);
  depth.resize(n + 1, -1);

  for (int x, i = 0; i < k; i++) {
    cin >> x;
    pack[0].push_back(x);
  }

  for (int x, i = 0; i < l; i++) {
    cin >> x;
    pack[1].push_back(x);
  }

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
      comp[u].push_back(v);
      comp[v].push_back(u);
      supEdge.push_back({u, v});
    }
  }

  for (auto i : pack[0]) {
    i = scc[i];
    serA[i] = 1;
  }

  for (auto i : pack[1]) {
    i = scc[i];
    serB[i] = 1;
  }

  for (int i = 1; i <= tplt; i++) {
    sA += serA[i];
    sB += serB[i];
  }

  for (int i = 1; i <= tplt; i++) {
    if (cnta[i] == -1 && cntb[i] == -1) {
      dfsCal(i, -1);
    }
  }

  for (auto [u, v] : supEdge) {
    if (depth[v] < depth[u]) {
      swap(u, v);
    }
    int ra = sA - cnta[v];
    int rb = sB - cntb[v];
    if (ra == 0 || rb == 0 || cnta[v] == 0 || cntb[v] == 0) {
      res++;
    }
  }

  cout << res;
}
