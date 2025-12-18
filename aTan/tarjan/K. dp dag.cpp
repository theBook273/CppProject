#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

int n, m;
vector<int> dis, adj[N + 5];
vector<bool> vis;

void dfs(int u) {
  for (auto v : adj[u]) {
    if (!dis[v]) {
      dfs(v);
    }
    dis[u] = max(dis[u], dis[v] + 1);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  dis.resize(n + 1, 0);

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int i = 1; i <= n; i++) {
    if (!dis[i]) {
      dfs(i);
    }
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, dis[i]);
  }
  cout << res;
}
