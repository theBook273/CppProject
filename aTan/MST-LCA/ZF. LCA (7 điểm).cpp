#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;
const int lg = 20;

vector<vector<int>> parent(N + 1, vector<int>(lg + 1, 0));
vector<int> depth(N + 1, 0), adj[N + 1];
int n, q, x, y, root;
char type;

void dfsSetUp(int u, int p) {
  for (auto &v : adj[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      parent[v][0] = u;
      dfsSetUp(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int x = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (x >= (1 << i)) {
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

int newLCA(int u, int v, int r) {
  if (r == 1) {
    return lca(u, v);
  } else {
    int x = lca(u, v);
    int res = x;
    int y = lca(u, r);
    int z = lca(v, r);
    if (depth[res] < depth[y]) {
      res = y;
    }
    if (depth[res] < depth[z]) {
      res = z;
    }
    return res;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("LCA.INP", "r", stdin);
  freopen("LCA.OUT", "w", stdout);

  cin >> n;
  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  root = 1;
  dfsSetUp(1, -1);
  init();

  cin >> q;
  while (q--) {
    cin >> type;
    if (type == '!') {
      cin >> root;
    } else {
      cin >> x >> y;
      cout << newLCA(x, y, root) << "\n";
    }
  }
}
