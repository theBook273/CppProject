#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100000;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) const { return len < other.len; }
};

int n, m, k;
vector<pair<int, int>> adj[N + 5];

vector<int> spec;
vector<int> dsu, sz, owner, dis;
vector<Edge> superEdge;

int acs(int x) { return (dsu[x] == x ? x : dsu[x] = acs(dsu[x])); }
bool join(int x, int y) {
  x = acs(x);
  y = acs(y);
  if (x != y) {
    if (sz[x] < sz[y])
      swap(x, y);
    sz[x] += sz[y];
    dsu[y] = x;
    return 1;
  }
  return 0;
}

void dijk() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

  for (int i = 1; i <= k; i++) {
    int s = spec[i];
    dis[s] = 0;
    owner[s] = s; // owner = chính nó
    q.push({0, s});
  }

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();
    if (du != dis[u])
      continue;

    for (auto [v, w] : adj[u]) {
      int nd = du + w;
      if (nd < dis[v]) {
        dis[v] = nd;
        owner[v] = owner[u];
        q.push({nd, v});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;

  spec.resize(k + 1);
  for (int i = 1; i <= k; i++)
    cin >> spec[i];

  for (int i = 1, u, v, c; i <= m; i++) {
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  dis.assign(n + 5, (int)4e18);
  owner.assign(n + 5, -1);

  // Bước 1: Dijkstra đa nguồn
  dijk();

  // Bước 2: Sinh siêu cạnh
  for (int u = 1; u <= n; u++) {
    for (auto &[v, w] : adj[u]) {
      int ou = owner[u];
      int ov = owner[v];
      if (ou != ov) {
        superEdge.push_back({ou, ov, dis[u] + dis[v] + w});
      }
    }
  }

  // Bước 3: Kruskal trên K đặc biệt
  dsu.resize(N + 5);
  sz.assign(N + 5, 1);
  iota(dsu.begin(), dsu.end(), 0);

  sort(superEdge.begin(), superEdge.end());

  int ans = 0, cnt = 0;
  for (auto &[u, v, w] : superEdge) {
    if (join(u, v)) {
      ans += w;
      cnt++;
      if (cnt == k - 1)
        break;
    }
  }

  cout << ans << "\n";
  return 0;
}
