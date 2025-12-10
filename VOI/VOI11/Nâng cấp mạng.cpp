#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;
const int MAXN = 1e5;
const int lg = 20;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len > other.len; }
};

vector<pair<int, int>> adj[MAXN];
vector<Edge> edge;
vector<int> dsu;
int parent[MAXN + 5][lg + 5], minP[MAXN + 5][lg + 5], depth[MAXN + 5];
int n, m, res = 0;

void dfs(int u, int p) {
  for (auto &[v, w] : adj[u]) {
    if (v != p) {
      parent[v][0] = u;
      minP[v][0] = w;
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
      minP[i][j] = min(minP[i][j - 1], minP[parent[i][j - 1]][j - 1]);
    }
  }
}

int minBetween(int u, int v) {
  int mini = oo;

  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  int x = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (x >= (1 << i)) {
      mini = min(mini, minP[u][i]);
      u = parent[u][i];
      x -= (1 << i);
    }
  }

  if (u == v) {
    return mini;
  }

  for (int i = lg; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      mini = min({mini, minP[u][i], minP[v][i]});

      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return min({mini, minP[u][0], minP[v][0]});
}

int acs(int x) { return (dsu[x] == x ? x : dsu[x] = acs(dsu[x])); }
bool join(int u, int v) {
  u = acs(u);
  v = acs(v);
  if (u != v) {
    dsu[v] = u;
    return 1;
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  dsu.resize(n + 1);
  iota(dsu.begin(), dsu.end(), 0);

  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }

  sort(edge.begin(), edge.end());

  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
  }

  dfs(1, 0);
  init();

  for (auto &[u, v, w] : edge) {
    res += max((minBetween(u, v)) - w, 0LL);
  }

  cout << res;
}
