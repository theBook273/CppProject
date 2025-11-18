#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;
const int MAXN = 1e5;
const int lg = 20;

struct Edge {
  int from, to, len, id;
  bool operator<(const Edge &other) { return len < other.len; }
};

vector<vector<int>> parent(MAXN + 5, vector<int>(lg + 5)),
    maxP(MAXN + 5, vector<int>(lg + 5, 0));
vector<pair<int, int>> adj[MAXN + 5];
vector<int> dsu, depth;
vector<Edge> edge;
vector<bool> res;
int n, m, sum = 0;

int acs(int x) { return (dsu[x] == x ? x : dsu[x] = acs(dsu[x])); }
bool join(int x, int y) {
  x = acs(x);
  y = acs(y);
  if (x != y) {
    dsu[x] = y;
    return 1;
  }
  return 0;
}

void dfsSetUp(int u, int p) {
  for (auto &[v, w] : adj[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      parent[v][0] = u;
      maxP[v][0] = w;
      dfsSetUp(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
      maxP[i][j] = max(maxP[i][j - 1], maxP[parent[i][j - 1]][j - 1]);
    }
  }
}

int maxBetween(int u, int v) {
  int maxi = -oo;
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int h = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (h >= (1 << i)) {
      maxi = max(maxi, maxP[u][i]);
      u = parent[u][i];
      h -= (1 << i);
    }
  }
  if (u == v) {
    return maxi;
  }
  for (int i = lg; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      maxi = max({maxi, maxP[u][i], maxP[v][i]});
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  return max({maxi, maxP[u][0], maxP[v][0]});
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  depth.resize(n + 1, 0), dsu.resize(n + 1);
  iota(dsu.begin(), dsu.end(), 0);
  res.resize(m, 0);

  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edge.push_back({u, v, w, i});
  }

  sort(edge.begin(), edge.end());

  for (auto &[u, v, w, id] : edge) {
    if (join(u, v)) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      sum += w;
      res[id] = 1;
    }
  }

  dfsSetUp(1, 0);
  init();

  for (auto &[u, v, w, id] : edge) {
    if (res[id] == 1) {
      continue;
    } else {
      int temp = sum - maxBetween(u, v) + w;
      res[id] = (temp == sum);
    }
  }

  for (auto i : res) {
    cout << i;
  }
}
