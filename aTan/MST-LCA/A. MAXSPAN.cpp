#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len > other.len; }
};

vector<int> dsu;
vector<Edge> edge;
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
  edge.resize(m);
  dsu.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }

  for (auto &[u, v, w] : edge) {
    cin >> u >> v >> w;
  }
  sort(edge.begin(), edge.end());

  int tong = 0;
  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      tong += w;
    }
  }

  cout << tong << "\n";
}
