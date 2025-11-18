#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5;
const int lg = 20;
const int INF = 1e18;

int parent[MAXN + 5][lg + 5], maxP[MAXN + 5][lg + 5], minP[MAXN + 5][lg + 5];
int depth[MAXN + 5];
vector<pair<int, int>> adj[MAXN + 5];
int n, k, x, y;

void dfsSetup(int u, int p) {
  for (auto &[v, w] : adj[u]) {
    if (v != p) {
      parent[v][0] = u;
      maxP[v][0] = w;
      minP[v][0] = w;
      depth[v] = depth[u] + 1;
      dfsSetup(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
      maxP[i][j] = max(maxP[i][j - 1], maxP[parent[i][j - 1]][j - 1]);
      minP[i][j] = min(minP[i][j - 1], minP[parent[i][j - 1]][j - 1]);
    }
  }
}

pair<int, int> lca(int u, int v) {
  int maxi = -INF, mini = INF;

  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  int h = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (h >= (1 << i)) {
      maxi = max(maxi, maxP[u][i]);
      mini = min(mini, minP[u][i]);
      u = parent[u][i];
      h -= (1 << i);
    }
  }

  if (u == v) {
    return {maxi, mini};
  }

  for (int i = lg; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      maxi = max({maxi, maxP[u][i], maxP[v][i]});
      mini = min({mini, minP[u][i], minP[v][i]});
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  maxi = max({maxi, maxP[u][0], maxP[v][0]});
  mini = min({mini, minP[u][0], minP[v][0]});

  return {maxi, mini};
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int u, v, w, i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfsSetup(1, -1);
  init();

  cin >> k;
  while (k--) {
    cin >> x >> y;
    auto [maxx, minx] = lca(x, y);
    cout << minx << " " << maxx << "\n";
  }
}
