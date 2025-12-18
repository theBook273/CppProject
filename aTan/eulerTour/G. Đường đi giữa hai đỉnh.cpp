#include <bits/stdc++.h>
#include <utility>
#define int long long

using namespace std;

struct Edge {
  int from, to, len;
};

const int N = 2e5;
const int lg = 20;

int n, q, timer = 0;
vector<vector<int>> parent;
vector<int> tin, tout, dis, depth, pos;
vector<pair<int, int>> adj[N + 5];
vector<Edge> edge;

void dfs(int u, int p) {
  tin[u] = ++timer;
  pos[timer] = u;
  for (auto [v, w] : adj[u]) {
    if (v == p) {
      continue;
    }
    parent[v][0] = u;
    dis[v] = dis[u] + w;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
  tout[u] = timer;
}

void init() {
  dfs(1, -1);
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      int mid = parent[i][j - 1];
      parent[i][j] = parent[mid][j - 1];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  int x = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (x & (1 << i)) {
      u = parent[u][i];
      x -= (1 << i);
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = lg; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[u][0];
}

int disBetween(int u, int v) { return (dis[u] + dis[v] - 2 * dis[lca(u, v)]); }

void update(int t, int x) {
  auto &[u, p, old] = edge[t];
  if (depth[u] < depth[p]) {
    swap(u, p);
  }
  for (int i = tin[u]; i <= tout[u]; ++i) {
    dis[pos[i]] = dis[pos[i]] - old + x;
  }
  old = x;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  parent.resize(N + 1, vector<int>(lg + 1, 0));
  edge.resize(N + 1, {0, 0, 0});
  tin.resize(N + 1, 0);
  tout.resize(N + 1, 0);
  pos.resize(N + 1, 0);
  dis.resize(N + 1, 0);
  depth.resize(N + 1, 0);

  cin >> n;
  for (int u, v, w, i(1); i <= n - 1; ++i) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    edge[i] = {u, v, w};
  }

  init();
  cin >> q;
  int type, u, v;
  while (q--) {
    cin >> type >> u >> v;
    if (type == 1) {
      update(u, v);
    } else {
      cout << disBetween(u, v) << "\n";
    }
  }
}
