#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int to, from, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

const int N = 1e5;
const int lg = 20;
const int oo = 1e18;

vector<vector<int>> parent(N + 1, vector<int>(lg + 1, 0)),
    shortest(50, vector<int>(N + 1, oo));
vector<Edge> edge;
vector<pair<int, int>> fullGraph[N + 5], adj[N + 5];
vector<int> dis, dsu, depth;
vector<int> special;
map<int, int> mp;
int n, m, q;

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

int minn(int u, int v) { return dis[u] + dis[v] - 2 * dis[lca(u, v)]; }

void dijisk(vector<int> &dis, int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  q.push({0, start});
  dis[start] = 0;
  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();
    if (du != dis[u]) {
      continue;
    }
    for (auto &[v, w] : fullGraph[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  dis.resize(n + 1, 0), depth.resize(n + 1, 0), dsu.resize(n + 1);
  iota(dsu.begin(), dsu.end(), 0);

  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }

  sort(edge.begin(), edge.end());

  for (auto &[u, v, w] : edge) {
    fullGraph[u].push_back({v, w});
    fullGraph[v].push_back({u, w});
    if (join(u, v)) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    } else {
      special.push_back(u);
      special.push_back(v);
    }
  }

  if (!special.empty()) {
    sort(special.begin(), special.end());
    special.erase(unique(special.begin(), special.end()), special.end());

    for (int i = 0; i < (int)special.size(); i++) {
      dijisk(shortest[i], special[i]);
    }
  }

  dfsSetUp(1, -1);
  init();

  cin >> q;
  int x, y;
  while (q--) {
    cin >> x >> y;
    int res = minn(x, y);
    if (!special.empty()) {
      for (int i = 0; i < (int)special.size(); i++) {
        res = min(res, shortest[i][x] + shortest[i][y]);
      }
    }
    cout << res << "\n";
  }
}
