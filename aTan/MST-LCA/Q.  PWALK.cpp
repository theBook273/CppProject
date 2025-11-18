#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5;
const int LGN = log2(MAXN);

vector<pair<int, int>> adj[MAXN + 5];
vector<int> depth, dis;
vector<vector<int>> parent;
int n, q;

void dfs(int u, int p) {
  for (auto &[v, w] : adj[u]) {
    if (v != p) {
      dis[v] = dis[u] + w;
      depth[v] = depth[u] + 1;
      parent[v][0] = u;
      dfs(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= LGN; j++) {
    for (int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
  }
}

int LCA(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  int h = depth[u] - depth[v];
  for (int i = LGN; i >= 0; i--) {
    if (h >= (1 << i)) {
      u = parent[u][i];
      h -= (1 << i);
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = LGN; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[u][0];
}

int disFromTo(int u, int v) { return dis[u] + dis[v] - 2 * dis[LCA(u, v)]; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;

  parent.resize(n + 1, vector<int>(LGN + 5, 0));
  dis.resize(n + 1, 0);
  depth.resize(n + 1, 0);
  for (int u, v, w, i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(1, 1);
  init();

  int x, y;
  while (q--) {
    cin >> x >> y;
    cout << disFromTo(x, y) << "\n";
  }
}
