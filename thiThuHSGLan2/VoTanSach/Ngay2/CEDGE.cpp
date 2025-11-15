#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int u, v;
};

vector<int> dsu;
vector<Edge> edge;
int n, m, res = 0;

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

void kruskal(int u, int v, int p) {
  for (int i = 0; i < m; i++) {
    if (i != p) {
      auto &[x, y] = edge[i];
      if (x == u || y == v || x == v || y == u) {
        continue;
      }
      join(x, y);
    }
  }
  set<int> se;
  for (int i = 1; i <= n; i++) {
    if (i == u || i == v) {
      continue;
    }
    se.insert(parent(i));
  }
  if (se.size() > 1) {
    res++;
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("CEDGE.INP", "r", stdin);
  freopen("CEDGE.OUT", "w", stdout);

  cin >> n >> m;
  dsu.resize(n + 1);
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    edge.push_back({u, v});
  }

  for (int i = 0; i < m; i++) {
    auto [u, v] = edge[i];
    kruskal(u, v, i);
  }
  cout << res;
}
