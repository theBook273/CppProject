#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

vector<Edge> edge;
vector<int> dsu, store;
unordered_set<int> se;
int n, m, k;

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

  freopen("TRADE.INP", "r", stdin);
  freopen("TRADE.OUT", "w", stdout);

  cin >> n >> m >> k;

  dsu.resize(n + 1);
  iota(dsu.begin(), dsu.end(), 0);
  for (int temp, i = 0; i < k; i++) {
    cin >> temp;
    store.push_back(temp);
  }

  edge.resize(m);
  for (auto &[u, v, w] : edge) {
    cin >> u >> v >> w;
  }
  for (auto i : store) {
    edge.push_back({0, i, 0});
  }

  int tong = 0;
  sort(edge.begin(), edge.end());
  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      tong += w;
    }
  }

  for (auto i : dsu) {
    se.insert(parent(i));
  }

  cout << (se.size() == 1 ? tong : -1) << "\n";
}
