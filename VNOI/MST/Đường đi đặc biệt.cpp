#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int oo = 1e18;

struct Edge {
  int from, to, len;
  const bool operator<(const Edge &other) { return len < other.len; }
};

int n, m, k;
vector<int> dsu, spec, own, dis;
vector<pair<int, int>> adj[N + 5];
vector<Edge> sedge;

void dijisk() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

  for (auto i : spec) {
    q.push({0, i});
    dis[i] = 0;
    own[i] = i;
  }

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != dis[u]) {
      continue;
    }

    for (auto [v, w] : adj[u]) {
      int nd = dis[u] + w;
      if (dis[v] > nd) {
        dis[v] = nd;
        own[v] = own[u];
        q.push({nd, v});
      }
    }
  }
}

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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;

  spec.resize(k);
  dsu.resize(n + 1);
  dis.resize(n + 1, oo);
  own.resize(n + 1);
  iota(dsu.begin(), dsu.end(), 0);

  for (auto &i : spec) {
    cin >> i;
  }

  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dijisk();

  for (int u = 1; u <= n; u++) {
    for (auto [v, w] : adj[u]) {
      int ou = own[u];
      int ov = own[v];
      if (ov != ou) {
        sedge.push_back({ou, ov, dis[u] + dis[v] + w});
      }
    }
  }

  sort(sedge.begin(), sedge.end());

  int res = 0;

  for (auto [u, v, w] : sedge) {
    if (join(u, v)) {
      res += w;
    }
  }

  cout << res;
}
