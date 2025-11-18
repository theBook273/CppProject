#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5;
const int LGN = ceil(log2(MAXN));

vector<vector<int>> parent;
vector<int> depth, cal, adj[MAXN + 5];
int n, q, res = 0;

void dfs(int u, int p) {
  for (auto v : adj[u]) {
    if (v != p) {
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

void mark(int u, int v) {
  cal[u]++;
  cal[v]++;
  cal[LCA(u, v)] -= 2;
}

void calc(int u, int p) {
  for (auto v : adj[u]) {
    if (v != p) {
      calc(v, u);
      cal[u] += cal[v];
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;

  parent.resize(n + 1, vector<int>(LGN + 5, 0));
  depth.resize(n + 1, 0);
  cal.resize(n + 1, 0);

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 1);
  init();

  cin >> q;
  int x, y;
  while (q--) {
    cin >> x >> y;
    mark(x, y);
  }

  calc(1, 1);
  for (int i = 2; i <= n; i++) {
    res += (cal[i] == 0);
  }

  cout << res << "\n";
}
