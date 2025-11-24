#include <bits/stdc++.h>

using namespace std;

const int N = 4e5;
const int lg = 20;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

vector<vector<int>> parent(N + 5, vector<int>(lg + 1));
vector<Edge> edge;
vector<int> compressed, a, depth(N + 5, 0), dis(N + 5, 0), dsu(N + 5);
vector<pair<int, double>> adj[N + 5];
int n;

int acs(int x) { return (dsu[x] == x ? x : dsu[x] = acs(dsu[x])); }
bool join(int u, int v) {
  u = acs(u);
  v = acs(v);
  if (v != u) {
    dsu[v] = u;
    return 1;
  }
  return 0;
}

void dfsSetUp(int u, int p) {
  for (auto &[v, w] : adj[u]) {
    if (v != p) {
      parent[v][0] = u;
      dis[v] = dis[u] + w;
      depth[v] = depth[u] + 1;
      dfsSetUp(v, u);
    }
  }
}

void init() {
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

int disBetween(int u, int v) { return dis[u] + dis[v] - 2 * dis[lca(u, v)]; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  iota(dsu.begin(), dsu.end(), 0);
  a.resize(n + 1);
  char temp;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    a[i] = temp;
  }
  a[0] = a[1];
  compressed = a;
  sort(compressed.begin(), compressed.end());
  compressed.erase(unique(compressed.begin(), compressed.end()),
                   compressed.end());
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(compressed.begin(), compressed.end(), a[i]) -
           compressed.begin() + 1 + n;
  }
  for (int i = 1; i <= n; i++) {
    join(i, a[i]);
    adj[i].push_back({a[i], 0.5});
    adj[a[i]].push_back({i, 0.5});
  }
  for (int u, v, i = 1; i < n; i++) {
    cin >> u >> v;
    edge.push_back({u, v, 1});
  }
  sort(edge.begin(), edge.end());
  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
  }
  for (int i = 1; i <= n + compressed.size(); i++) {
    cout << i << ":\n";
    for (auto [u, v] : adj[i]) {
      cout << " " << u << " " << v << "\n";
    }
    cout << "\n";
  }
  // dfsSetUp(1, -1);
  // init();
}
