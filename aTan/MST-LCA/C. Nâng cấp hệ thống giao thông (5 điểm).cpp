#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

vector<Edge> edge;
vector<int> dsu;
int n, m;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
bool join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    dsu[y] = x;
    return 1;
  }
  return 0;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;

  dsu.resize(n + 1);
  edge.resize(m);

  for (auto &[u, v, w] : edge) {
    cin >> u >> v >> w;
  }
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }

  sort(edge.begin(), edge.end());

  int tong = 0;
  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      tong += w;
    }
  }

  unordered_set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(parent(i));
  }

  if (se.size() == 1) {
    cout << 1 << " " << tong << "\n";
  } else {
    cout << 0 << " " << se.size() - 1 << "\n";
  }
}
