#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5;

vector<pair<int, int>> edge, adj[N + 5];
vector<int> num, low, scc, comp[N + 5];
stack<int> st;
int n, m, res = 0, timer = 0, tplt = 0;

void tajan(int u, int lastId) {
  low[u] = num[u] = ++timer;
  st.push(u);
  for (auto &[v, id] : adj[u]) {
    if (id != lastId) {
      if (!num[v]) {
        tajan(v, id);
      }
      low[u] = min(low[u], low[v]);
    }
  }

  if (low[u] == num[u]) {
    int v;
    tplt++;
    do {
      v = st.top();
      scc[v] = tplt;
      st.pop();
    } while (v != u);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("DOANDUONGPHU.INP", "r", stdin);
  freopen("DOANDUONGPHU.OUT", "w", stdout);

  cin >> n >> m;

  scc.resize(n + 1, 0);
  low.resize(n + 1, 0);
  num.resize(n + 1, 0);

  for (int u, v, i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    edge.push_back({u, v});
  }

  for (int i = 1; i <= n; i++) {
    if (!num[i]) {
      tajan(i, -1);
    }
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
    if (comp[i].size() == 1) {
      res++;
    }
  }

  cout << ceil(res / 2.0);
}
