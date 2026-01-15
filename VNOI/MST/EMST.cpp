#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int u, v, w, id;
  const bool operator<(const Edge &other) { return w < other.w; }
};

const int N = 2e5;
const int lg = 20;
const int oo = 1e18;

int n, m, mst = 0, cnt = 0;
vector<vector<int>> parent, maxx;
vector<Edge> edge;
vector<int> dsu, res, depth;
vector<pair<int, int>> adj[N + 5];

int acs(int x) { return (dsu[x] == x ? x : dsu[x] = acs(dsu[x])); }
bool join(int u, int v) {
  u = acs(u);
  v = acs(v);
  if (u != v) {
    dsu[u] = v;
    return 1;
  }
  return 0;
}

void dfsSetUp(int u, int p) {
  for (auto [v, w] : adj[u]) {
    if (v == p) {
      continue;
    }

    parent[v][0] = u;
    maxx[v][0] = w;
    depth[v] = depth[u] + 1;
    dfsSetUp(v, u);
  }
}

void init() {
  dfsSetUp(1, -1);

  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      int mid = parent[i][j - 1];
      parent[i][j] = parent[mid][j - 1];
      maxx[i][j] = max(maxx[i][j - 1], maxx[mid][j - 1]);
    }
  }
}

int maxBet(int u, int v) {
  int maxi = -oo;
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  int x = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (x & (1 << i)) {
      maxi = max(maxi, maxx[u][i]);
      u = parent[u][i];
      x -= (1 << i);
    }
  }

  if (u == v) {
    return maxi;
  }

  for (int i = lg; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      maxi = max({maxi, maxx[u][i], maxx[v][i]});
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return max({maxi, maxx[u][0], maxx[v][0]});
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  maxx.resize(n + 1, vector<int>(lg + 1, -oo));
  parent.resize(n + 1, vector<int>(lg + 1, 0));

  res.resize(m, 0);
  depth.resize(n + 1, 0);

  dsu.resize(n + 1, 0);
  iota(dsu.begin(), dsu.end(), 0);

  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edge.push_back({u, v, w, i});
  }

  sort(edge.begin(), edge.end());

  for (auto [u, v, w, i] : edge) {
    if (join(u, v)) {
      mst += w;
      res[i] = 1;
      cnt++;

      adj[u].push_back({v, w});
      adj[v].push_back({u, w});

      if (cnt == n - 1) {
        break;
      }
    }
  }

  init();

  for (auto [u, v, w, id] : edge) {
    if (res[id]) {
      res[id] = mst;
    } else {
      res[id] = mst - maxBet(u, v) + w;
    }
  }

  for (auto &i : res) {
    cout << i << "\n";
  }
}
