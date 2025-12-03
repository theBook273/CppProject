#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

vector<int> roadIn, roadOut, id, low, scc, adj[N + 5];
vector<pair<int, int>> edge;
vector<bool> outstack;
stack<int> st;
int n, m, tplt = 0, timer = 0, x = 0, y = 0;

void tarjan(int u) {
  low[u] = id[u] = ++timer;
  st.push(u);

  for (auto v : adj[u]) {
    if (!outstack[v]) {
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
      outstack[v] = 1;
      scc[v] = tplt;
      st.pop();
    } while (v != u);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  scc.resize(n + 1, 0);
  id.resize(n + 1, 0);
  low.resize(n + 1, 0);
  roadIn.resize(n + 1, 0);
  roadOut.resize(n + 1, 0);
  outstack.resize(n + 1, 0);

  for (int u, v, i = 1; i <= m; i++) {
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
      roadIn[v]++;
      roadOut[u]++;
    }
  }

  for (int i = 1; i <= tplt; i++) {
    if (roadIn[i] == 0) {
      x++;
    }
    if (roadOut[i] == 0) {
      y++;
    }
  }

  cout << max(x, y);
}
