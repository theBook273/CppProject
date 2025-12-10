#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5;

int n, timer, t;
vector<int> dis, tin, tout, pos, a, adj[N + 5];
vector<bool> vis;

void dfsSetup(int u) {
  tin[u] = ++timer;
  pos[timer] = u;
  dis[u] += a[u];
  for (auto &v : adj[u]) {
    if (vis[v]) {
      continue;
    }

    vis[v] = 1;
    dis[u] += dis[v];
    dfsSetup(v);
  }
  tout[u] = timer;
}

int query(int u) {
  int res = 0;
  int c = dis[u] - a[u];
  for (int i = tin[u]; i <= tout[u]; i++) {
    res += (dis[pos[i]] == c);
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);

  cin >> n >> t;

  a.resize(N + 1, 0);
  tin.resize(N + 1, 0);
  tout.resize(N + 1, 0);
  vis.resize(N + 1, 0);
  pos.resize(2 * N + 1, 0);
  dis.resize(N + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      a[i] = -1;
    }
  }

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfsSetup(1);

  while (t--) {
    int x;
    cin >> x;
    cout << query(x) << "\n";
  }
}
