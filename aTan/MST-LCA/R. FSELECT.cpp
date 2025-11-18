#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
const int LGN = ceil(log2(MAXN));

vector<vector<int>> parent;
vector<int> depth, adj[MAXN + 5], appoint[MAXN / 2 + 5];
int n, k, root;

void dfsSetup(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      parent[v][0] = u;
      depth[v] = depth[u] + 1;
      dfsSetup(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= LGN; j++) {
    for (int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  int h = depth[u] - depth[v];
  for (int i = LGN; i >= 0; i--) {
    if (h >= (1 << i)) {
      u = parent[u][i];
      h -= (1 << i);
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = LGN; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[u][0];
}

int dis(int u, int v) { return (depth[u] + depth[v] - 2 * depth[lca(u, v)]); }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  depth.resize(n + 1, 0);
  parent.resize(n + 1, vector<int>(LGN + 5, 0));

  for (int x, y, i = 1; i <= n; i++) {
    cin >> x >> y;
    appoint[x].push_back(i);
    if (y == 0) {
      root = i;
      continue;
    }
    adj[i].push_back(y);
    adj[y].push_back(i);
  }

  dfsSetup(root, -1);
  init();

  for (int i = 1; i <= k; i++) {
    int res = 0;
    for (auto a : appoint[i]) {
      for (auto b : appoint[i]) {
        if (a != b) {
          res = max(dis(a, b), res);
        }
      }
    }
    cout << res << "\n";
  }
}
