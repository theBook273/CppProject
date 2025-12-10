#include <bits/stdc++.h>

using namespace std;

const int N = 4e5;

int n, q, timer = 0;
vector<int> tin, tout, pos, a, adj[N + 5];

void dfsSetup(int u, int p) {
  tin[u] = ++timer;
  pos[timer] = u;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }

    dfsSetup(v, u);
  }
  tout[u] = timer;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  tin.resize(N + 5, 0);
  tout.resize(N + 5, 0);
  pos.resize(N + 5, 0);
  a.resize(N + 5, 0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfsSetup(1, -1);

  int type, u, c;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> u >> c;
      a[u] = c;
    } else {
      unordered_set<int> se;
      cin >> u;
      for (int i = tin[u]; i <= tout[u]; i++) {
        se.insert(a[pos[i]]);
      }
      cout << se.size() << "\n";
    }
  }
}
