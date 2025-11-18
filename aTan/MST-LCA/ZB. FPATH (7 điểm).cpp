#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int to, from, len;
  bool operator<(const Edge &other) { return len > other.len; }
};

set<int> se;
vector<Edge> edge;
vector<int> dsu;
int n, m, res = LLONG_MAX;

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

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  dsu.resize(n + 1), iota(dsu.begin(), dsu.end(), 0);
  edge.resize(m);
  for (auto &[u, v, w] : edge) {
    cin >> u >> v >> w;
  }
  sort(edge.begin(), edge.end());
  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      res = min(res, w);
    }
  }
  for (int i = 1; i <= n; i++) {
    se.insert(parent(i));
  }
  if (se.size() == 1) {
    cout << res << "\n";
  } else {
    cout << -1 << "\n";
  }
}
