#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int oo = 1e18;

int n, m, timer = 0, tplt = 0, bridge = 0, res = -oo;
vector<pair<int, int>> edge, adj[N + 5];
vector<int> exist, dis, scc, num, low, comp[N + 5];
stack<int> st;

void tarjan(int u, int lastid) {
  low[u] = num[u] = ++timer;
  st.push(u);

  for (auto [v, id] : adj[u]) {
    if (id != lastid) {
      if (!num[v]) {
        tarjan(v, id);
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], num[v]);
      }
    }
  }

  if (low[u] == num[u]) {
    tplt++;
    // cout << tplt << ": ";
    int v;
    do {
      v = st.top();
      // cout << v << " ";
      scc[v] = tplt;
      st.pop();
    } while (v != u);
    // cout << "\n";
  }
}

void bfs(int x) {
  queue<int> q;
  dis[x] = 0;
  q.push(x);
  exist.push_back(x);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : comp[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        exist.push_back(v);
        q.push(v);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  num.resize(n + 1, 0);
  low.resize(n + 1, 0);
  scc.resize(n + 1, 0);
  dis.resize(n + 1, oo);

  for (int u, v, i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    edge.push_back({u, v});
  }

  for (int i = 1; i <= n; i++) {
    if (!num[i]) {
      tarjan(i, -1);
    }
  }

  for (auto [u, v] : edge) {
    u = scc[u];
    v = scc[v];
    if (u != v) {
      bridge++;
      comp[u].push_back(v);
      comp[v].push_back(u);
    }
  }

  for (int i = 1; i <= tplt; i++) {
    if (dis[i] == oo) {
      exist.clear();
      bfs(i);
      int maxi = 0, u = 0;
      for (auto v : exist) {
        if (maxi < dis[v]) {
          maxi = dis[v];
          u = v;
        }
      }

      for (auto v : exist) {
        dis[v] = oo;
      }

      exist.clear();
      bfs(u);
      maxi = 0;
      for (auto v : exist) {
        maxi = max(maxi, dis[v]);
      }

      res = max(res, maxi);
    }
  }

  cout << bridge - res;
}
