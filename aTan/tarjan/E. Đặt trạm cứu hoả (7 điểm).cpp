#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

struct Edge {
  int from, to;
};

stack<int> st;
vector<Edge> edge;
vector<bool> outStack;
vector<int> roadIn, scc, id, low, adj[N + 5];
int n, m, timer = 0, tplt = 0, res = 0;

void tarjan(int u) {
  low[u] = id[u] = ++timer;
  st.push(u);
  for (auto v : adj[u]) {
    if (!outStack[v]) {
      if (!id[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], low[v]);
      }
    }
  }
  if (id[u] == low[u]) {
    tplt++;
    int v;
    do {
      v = st.top();
      scc[v] = tplt;
      outStack[v] = 1;
      st.pop();
    } while (v != u);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("HELI.INP", "r", stdin);
  freopen("HELI.OUT", "w", stdout);

  cin >> n >> m;
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    edge.push_back({u, v});
  }

  id.resize(n + 1, 0);
  low.resize(n + 1, 0);
  scc.resize(n + 1, 0);
  outStack.resize(n + 1, 0);
  roadIn.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    if (!id[i]) {
      tarjan(i);
    }
  }

  for (auto [u, v] : edge) {
    u = scc[u];
    v = scc[v];
    if (u != v) {
      roadIn[v]++;
    }
  }

  for (int i = 1; i <= tplt; i++) {
    if (roadIn[i] == 0) {
      res++;
    }
  }

  cout << res;
}
