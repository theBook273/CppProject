#include <bits/stdc++.h>

using namespace std;

struct edge {
  int to, len;
};

const int lg = 20;
vector<edge> adj[10009];
int depth[10009], distRoot[10009], up[10009][20];

void dfs(int u, int p) {
  up[u][0] = p;

  for (int i = 1; i < lg; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }

  for (auto i : adj[u]) {
    if (i.to == p) {
      continue;
    }
    depth[i.to] = depth[u] + 1;
    distRoot[i.to] = distRoot[u] + i.len;
    dfs(i.to, u);
  }
}

void build(int root) {
  depth[root] = 0;
  distRoot[root] = 0;
  dfs(root, root);
}

int lift(int u, int k) {
  for (int i = 0; i < lg; i++) {
    if (k & (1 << i)) {
      u = up[u][i];
    }
  }
  return u;
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  u = lift(u, depth[u] - depth[v]);

  if (u == v)
    return u;

  for (int i = lg - 1; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }

  return up[u][0];
}

int dist(int u, int v) {
  int overlap = lca(u, v);
  return distRoot[u] + distRoot[v] - 2 * distRoot[overlap];
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;

  for (int u, v, w, i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  build(1);

  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << dist(u, v) << "\n";
  }
}
