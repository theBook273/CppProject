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

  dsu[0] = 0;
  for (int temp, i = 1; i <= n; i++) {
    cin >> temp;
    edge.push_back({0, i, temp});
    dsu[i] = i;
  }

  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }

  sort(edge.begin(), edge.end());

  int sum = 0;

  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      sum += w;
    }
  }

  cout << sum << "\n";
}
