#include <bits/stdc++.h>

using namespace std;

const int N(1e4);

int n, m;
vector<int> adj[N + 5];
set<pair<int, int>> edge;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    edge.insert({u, v});
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (auto [a, b] : edge) {
    if (a != b) {
    }
  }
}
