#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;
const int MOD = 1e9 + 7;

int n, m, timer = 0, tplt = 0;
vector<pair<int, int>> edge, adj[N + 5];
vector<int> id, low, scc, supsize, comp[N + 5];
stack<int> st;

int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }

void tarjan(int u, int last) {
  id[u] = low[u] = ++timer;
  st.push(u);
  for (auto [v, now] : adj[u]) {
    if (now == last) {
      continue;
    }
    if (id[v]) {
      low[u] = min(low[u], id[v]);
    } else {
      tarjan(v, now);
      low[u] = min(low[u], low[v]);
    }
  }

  if (low[u] == id[u]) {
    int v;
    tplt++;
    do {
      v = st.top();
      st.pop();
      scc[v] = tplt;
      supsize[tplt]++;
    } while (v != u);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);

  cin >> n >> m;

  scc.resize(n + 1, 0);
  id.resize(n + 1, 0);
  low.resize(n + 1, 0);
  supsize.resize(n + 1, 0);

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    edge.push_back({u, v});
  }

  tarjan(1, -1);

  for (auto [u, v] : edge) {
    u = scc[u];
    v = scc[v];
    if (u != v) {
      comp[u].push_back(v);
      comp[v].push_back(u);
    }
  }

  int asize = 0, way = 1;

  if (tplt == 1) {
    asize = 1;
    way = supsize[1];
  } else {
    for (int i = 1; i <= tplt; i++) {
      if (comp[i].size() == 1) {
        asize++;
        way = mul(way, supsize[i]);
      }
    }
  }

  cout << asize << " " << way << "\n";
}
