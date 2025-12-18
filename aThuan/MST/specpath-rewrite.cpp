#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int oo = 1e18;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

int n, m, k;
vector<pair<int, int>> adj[N + 5];
vector<int> spec, dsu, sz, owner, dis;
vector<Edge> supEdge;

int acs(int x) { return (dsu[x] == x ? x : dsu[x] = acs(dsu[x])); }
bool join(int x, int y) {
  x = acs(x);
  y = acs(y);
  if (x != y) {
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
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
    owner[s] = s;
    q.push({0, s});
  }

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != dis[u]) {
      continue;
    }

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
  dsu.resize(N + 5, 0);
  sz.resize(N + 5, 0);
  iota(dsu.begin(), dsu.end(), 0);
  dis.resize(n + 5, oo);
  owner.resize(n + 5, -1);

  for (int i = 1; i <= k; i++) {
    cin >> spec[i];
  }

  for (int u, v, w, i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dijk();
  for (int u = 1; u <= n; u++) {
    for (auto [v, w] : adj[u]) {
      if (owner[u] != owner[v]) {
        supEdge.push_back({owner[u], owner[v], dis[u] + dis[v] + w});
      }
    }
  }

  sort(supEdge.begin(), supEdge.end());

  int ans = 0, cnt = 0;
  for (auto [u, v, w] : supEdge) {
    if (join(u, v)) {
      ans += w;
      cnt++;
      if (cnt == k - 1) {
        break;
      }
    }
  }

  cout << ans;
}
