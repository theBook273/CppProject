#include <bits/stdc++.h>
#include <climits>
#define int long long

using namespace std;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len > other.len; }
};

vector<Edge> edge;
vector<int> a, dsu, sz, res;
int n, m;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
bool join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    sz[x] += sz[y];
    dsu[y] = x;
    return 1;
  }
  return 0;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  a.resize(n + 1), dsu.resize(n + 1), sz.resize(n + 1, 1),
      res.resize(n + 1, -1);
  iota(dsu.begin(), dsu.end(), 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    edge.push_back({u, v, min(a[u], a[v])});
  }

  sort(edge.begin(), edge.end());
  res[1] = *max_element(a.begin(), a.end());
  for (auto [u, v, w] : edge) {
    if (join(u, v)) {
      u = parent(u);
      res[sz[u]] = max(res[sz[u]], w);
    }
  }

  for (int i = n - 1; i >= 1; i--) {
    res[i] = max(res[i], res[i + 1]);
  }

  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
}
