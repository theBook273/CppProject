#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;
int n, q, timer = 0;
vector<int> tin, tout, pos, color, adj[N + 5];

void dfs(int u, int p) {
  tin[u] = ++timer;
  pos[timer] = u;

  for (auto v : adj[u]) {
    if (v == p) {
      continue;
    }

    dfs(v, u);
  }

  tout[u] = timer;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;

  color.resize(n + 1, 0);
  tin.resize(n + 1, 0);
  tout.resize(n + 1, 0);
  pos.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> color[i];
  }

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, -1);

  int type, x, y;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> x >> y;
      color[x] = y;
    } else {
      cin >> x;
      unordered_set<int> se;
      for (int i = tin[x]; i <= tout[x]; i++) {
        se.insert(color[pos[i]]);
      }
      cout << se.size() << "\n";
    }
  }
}
