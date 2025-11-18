#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5;
const int LNG = ceil(log2(MAXN));

vector<int> adj[MAXN + 5];
vector<vector<int>> parent;
vector<int> depth;
int n;

void dfs(int u, int p) {
  for (auto &v : adj[u]) {
    if (v != p) {
      parent[v][0] = u;
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= LNG; j++) {
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
  for (int i = LNG; i >= 0; i--) {
    if (h >= (1 << i)) {
      u = parent[u][i];
      h -= (1 << i);
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = LNG; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[u][0];
}

int calcDis(int x, int y) { return depth[x] + depth[y] - 2 * depth[LCA(x, y)]; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  depth.resize(n + 1, 0);
  parent.resize(n + 1, vector<int>(LNG + 5));

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 1);
  init();

  for (int i = 1; i <= n; i++) {
    int tong = 0;
    for (int j = 0; j + i <= n; j += i) {
      tong += (calcDis(j, j + i));
    }
    cout << (i == 1 ? tong : tong * 2) << "\n";
  }
}
