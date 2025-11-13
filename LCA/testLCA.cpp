#include <bits/stdc++.h>

using namespace std;

struct edge {
  int v, w;
};

const int lg = 20;

vector<edge> adj[100000];
int up[100000][lg], depth[100000];

void dfs(int u, int p) {
  up[u][0] = p;
  for (int i = 1; i < lg; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }

  for (auto i : adj[u]) {
    if (i.v == p)
      continue;
    depth[i.v] = depth[u] + 1;
    dfs(i.v, u);
  }
}

void build(int root) {
  depth[root] = 0;
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

int LCA(int u, int v) {
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
  int lca = LCA(u, v);
  return depth[u] + depth[v] - 2 * depth[lca];
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back({v, 0});
    adj[v].push_back({u, 0});
  }

  build(1);

  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << dist(u, v) << "\n";
  }
}
