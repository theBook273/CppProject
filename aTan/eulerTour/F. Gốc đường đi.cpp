#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;

int n, q, timer = 0;
vector<int> tint, tout, pos, a, dis, adj[N + 5];

void dfsSetup(int u, int p) {
  tint[u] = ++timer;
  pos[timer] = u;
  dis[u] += a[u];
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }

    dis[v] += dis[u];
    dfsSetup(v, u);
  }
  tout[u] = timer;
}

void update(int u, int x) {
  int old = a[u];
  for (int i = tint[u]; i <= tout[u]; i++) {
    dis[pos[i]] = dis[pos[i]] - old + x;
  }
  a[u] = x;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  tint.resize(N + 5, 0);
  tout.resize(N + 5, 0);
  pos.resize(N + 5, 0);
  a.resize(N + 5, 0);
  dis.resize(N + 5, 0);

  cin >> n >> q;
  for (int i(1); i <= n; ++i) {
    cin >> a[i];
  }

  for (int u, v, i(0); i < n - 1; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfsSetup(1, -1);
  int type, u, x;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> u >> x;
      update(u, x);
    } else {
      cin >> u;
      cout << dis[u] << "\n";
    }
  }
}
