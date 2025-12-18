#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int oo = 4e18;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

int n, m, k, ansTele = 0, ans1T = oo, cnt = 0;
vector<int> spec, dsu, dis, dis1, owner;
vector<pair<int, int>> adj[N + 5];
vector<Edge> edge;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
bool join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    dsu[x] = y;
    return 1;
  }
  return 0;
}

void dijikSpec() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

  for (auto i : spec) {
    q.push({0, i});
    dis[i] = 0;
    owner[i] = i;
  }

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != dis[u]) {
      continue;
    }

    for (auto [v, w] : adj[u]) {
      int nd = dis[u] + w;
      if (nd < dis[v]) {
        dis[v] = nd;
        owner[v] = owner[u];
        q.push({nd, v});
      }
    }
  }
}

void disjikF1() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  q.push({0, 1});
  dis1[1] = 0;

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != dis1[u]) {
      continue;
    }

    for (auto [v, w] : adj[u]) {
      int nd = dis1[u] + w;
      if (nd < dis1[v]) {
        dis1[v] = nd;
        q.push({nd, v});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // vector<int> spec, dsu, dis, dis1, owner;
  // vector<pair<int, int>> adj[N + 5];

  cin >> n >> m;

  dis.resize(n + 1, oo);
  dis1.resize(n + 1, oo);
  owner.resize(n + 1, -1);

  dsu.resize(n + 1, 0);
  iota(dsu.begin(), dsu.end(), 0);

  for (int u, v, w, i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  cin >> k;
  for (int x, i = 0; i < k; i++) {
    cin >> x;
    spec.push_back(x);
  }

  dijikSpec();
  disjikF1();

  for (auto i : spec) {
    ans1T = min(ans1T, dis1[i]);
  }

  for (int u = 1; u <= n; u++) {
    for (auto [v, w] : adj[u]) {
      if (owner[v] != owner[u]) {
        edge.push_back({owner[v], owner[u], dis[v] + dis[u] + w});
      }
    }
  }

  sort(edge.begin(), edge.end());

  for (auto [u, v, w] : edge) {
    if (join(u, v)) {
      ansTele += w;
      cnt++;
      if (cnt == k - 1) {
        break;
      }
    }
  }

  cout << ans1T + ansTele;
}
