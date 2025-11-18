#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;
const int MAXN = 8e4;
const int lg = log2(MAXN);

vector<pair<int, int>> adj[MAXN + 5], newGraph[MAXN + 5];
int parent[MAXN][22];
int dis[MAXN + 5], depth[MAXN + 5], res[MAXN + 5];
int n;

void dfsSetUp(int u, int p) {
  for (auto &[v, w] : adj[u]) {
    if (v != p) {
      parent[v][0] = u;
      dis[v] = dis[u] + w;
      depth[v] = depth[u] + 1;
      dfsSetUp(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  int h = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (h >= (1 << i)) {
      u = parent[u][i];
      h -= (1 << i);
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = lg; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[u][0];
}

int D(int u, int v) { return dis[u] + dis[v] - 2 * dis[lca(u, v)]; }

void dijisk(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  q.push({0, start});
  res[start] = 0;

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != res[u]) {
      continue;
    }

    for (auto &[v, w] : newGraph[u]) {
      if (res[v] > res[u] + w) {
        res[v] = res[u] + w;
        q.push({res[v], v});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("FSP.INP", "r", stdin);
  // freopen("FSP.OUT", "w", stdout);

  memset(parent, 0, sizeof(parent));
  parent[1][0] = 0;
  dis[1] = 0;
  depth[1] = 0;

  cin >> n;
  for (int u, v, w, i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfsSetUp(1, 0);
  init();

  vector<int> dp(n + 1, oo);
  dp[1] = 0;

  for (int j = 2; j <= n; ++j) {
    int best = oo;
    for (int i = 1; i < j; ++i) {
      int cand = dp[i] + D(i, j);
      if (cand < best)
        best = cand;
    }
    dp[j] = best;
  }

  for (int i = 1; i <= n; ++i) {
    if (i > 1)
      cout << ' ';
    cout << dp[i];
  }
  cout << '\n';
}
