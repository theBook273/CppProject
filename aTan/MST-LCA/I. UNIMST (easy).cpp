#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#define int long long

using namespace std;

const int N = 2e5;
const int lg = ceil(log2(N));
const int oo = 1e18;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

vector<vector<int>> p(N + 1, vector<int>(lg + 1, 0)),
    maxp(N + 1, vector<int>(lg + 1, -oo));
vector<Edge> edge, outter;
vector<pair<int, int>> adj[N + 5];
vector<int> dsu(N + 1), depth(N + 1, 0);
int n, m, res = 0;

int acs(int x) { return (dsu[x] == x ? x : dsu[x] = acs(dsu[x])); }
bool join(int a, int b) {
  a = acs(a);
  b = acs(b);
  if (b != a) {
    dsu[a] = b;
    return 1;
  }
  return 0;
}

void dfsSetUp(int u, int par) {
  for (auto &[v, w] : adj[u]) {
    if (v != par) {
      maxp[v][0] = w;
      p[v][0] = u;
      depth[v] = depth[u] + 1;
      dfsSetUp(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      int mid = p[i][j - 1];
      p[i][j] = p[mid][j - 1];
      maxp[i][j] = max(maxp[i][j - 1], maxp[mid][j - 1]);
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
      maxi = max(maxi, maxp[u][i]);
      u = p[u][i];
      x -= (1 << i);
    }
  }
  if (u == v) {
    return maxi;
  }
  for (int i = lg; i >= 0; i--) {
    if (p[u][i] != p[v][i]) {
      maxi = max({maxi, maxp[u][i], maxp[v][i]});
      u = p[u][i];
      v = p[v][i];
    }
  }
  return max({maxi, maxp[u][0], maxp[v][0]});
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  iota(dsu.begin(), dsu.end(), 0);

  cin >> n >> m;
  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }

  sort(edge.begin(), edge.end());
  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    } else {
      outter.push_back({u, v, w});
    }
  }

  dfsSetUp(1, -1);
  init();

  for (auto &[u, v, w] : outter) {
    if (w == maxBetween(u, v)) {
      res++;
    }
  }

  cout << res;
}
