#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int lg = 20;
const int oo = 1e18;

int n, c, q;
vector<int> a, dis, depth, adj[N + 5];
map<int, vector<int>> co;
vector<vector<int>> parent(N + 5, vector<int>(lg + 5, 0));

void dfsSetUp(int u, int p) {
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    parent[v][0] = u;
    depth[v] = depth[u] + 1;
    dis[v] = dis[u] + 1;
    dfsSetUp(v, u);
  }
}

void init() {
  dfsSetUp(1, -1);
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

int disBet(int u, int v) { return dis[u] + dis[v] - 2 * dis[lca(u, v)]; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  a.resize(N + 1, 0);
  depth.resize(N + 1, 0);
  dis.resize(N + 1, 0);

  cin >> n;
  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  init();

  cin >> c;
  for (int x, i = 1; i <= n; i++) {
    cin >> x;
    co[x].push_back(i);
  }

  cin >> q;
  int st, tar;
  while (q--) {
    cin >> st >> tar;
    if (co[tar].empty()) {
      cout << "-1\n";
    } else {
      int res = oo;
      for (int i : co[tar]) {
        res = min(res, disBet(st, i));
      }
      cout << res << "\n";
    }
  }
}
