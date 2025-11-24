#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5;
const int lg = 20;
const int oo = 1e18;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

vector<vector<int>> parent(N + 1, vector<int>(lg + 1, 0)),
    maxP(N + 1, vector<int>(lg + 1, -oo));
vector<pair<int, int>> adj[N + 5];
vector<Edge> edge;
vector<int> dsu, depth;
vector<bool> mark;
int n, m, sum;

int acs(int u) { return (dsu[u] == u ? u : dsu[u] = acs(dsu[u])); }
bool join(int a, int b) {
  a = acs(a);
  b = acs(b);
  if (a != b) {
    dsu[a] = b;
    return 1;
  }
  return 0;
}

void dfsSetUp(int u, int p) {
  for (auto &[v, w] : adj[u]) {
    if (v != p) {
      maxP[v][0] = w;
      parent[v][0] = u;
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
      maxP[i][j] = max(maxP[i][j - 1], maxP[mid][j - 1]);
    }
  }
}

int maxBetween(int u, int v) {
  int maxi = -oo;
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int x = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (x >= (1 << i)) {
      maxi = max(maxi, maxP[u][i]);
      u = parent[u][i];
      x -= (1 << i);
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

  freopen("MAYTINH.INP", "r", stdin);
  freopen("MAYTINH.OUT", "w", stdout);

  cin >> n >> m;

  dsu.resize(n + 1), depth.resize(n + 1, 0);
  iota(dsu.begin(), dsu.end(), 0);
  mark.resize(m, 0);

  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }

  sort(edge.begin(), edge.end());

  for (int i = 0; i < m; i++) {
    auto &[u, v, w] = edge[i];
    if (join(u, v)) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      mark[i] = 1;
      sum += w;
    }
  }

  dfsSetUp(1, -1);
  init();

  cout << sum << " ";
  int sum2 = oo;

  for (int i = 0; i < m; i++) {
    if (!mark[i]) {
      auto &[u, v, w] = edge[i];
      sum2 = min(sum2, sum - maxBetween(u, v) + w);
    }
  }
  cout << sum2;
}
