#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 273;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) const { return len > other.len; }
};

struct Query {
  int k, u, id;
  bool operator<(const Query &other) const { return k > other.k; }
};

int dsu[MAXN], sz[MAXN], n, q;
vector<Edge> edge;
vector<Query> query;
vector<int> res;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
void join(int a, int b) {
  a = parent(a);
  b = parent(b);

  if (a == b) {
    return;
  }

  if (sz[a] < sz[b])
    swap(a, b);
  sz[a] += sz[b];
  dsu[b] = a;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("QKGRAPH.INP", "r", stdin);
  freopen("QKGRAPH.OUT", "w", stdout);

  cin >> n >> q;
  res.resize(q + 1);

  for (int i = 1; i <= n; i++) {
    sz[i] = 1;
    dsu[i] = i;
  }

  for (int u, v, len, i = 1; i <= n - 1; i++) {
    cin >> u >> v >> len;
    edge.push_back({u, v, len});
  }

  for (int i = 1; i <= q; i++) {
    int u, k;
    cin >> k >> u;
    query.push_back({k, u, i});
  }

  sort(edge.begin(), edge.end());
  sort(query.begin(), query.end());

  // for (auto [i, j, w] : edge) {
  //   cout << i << " " << j << " " << w << "\n";
  // }
  //
  // for (auto [k, u, id] : query) {
  //   cout << k << " " << u << "\n";
  // }

  int edCnt = 0;
  for (auto [k, u, id] : query) {
    while (edge[edCnt].len >= k) {
      join(edge[edCnt].to, edge[edCnt].from);
      edCnt++;
    }
    res[id] = sz[parent(u)] - 1;
  }

  for (int i = 1; i <= q; i++) {
    cout << res[i] << "\n";
  }
}
