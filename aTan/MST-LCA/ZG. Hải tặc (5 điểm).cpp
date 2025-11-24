#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;
const int lg = 20;

struct Road {
  int to, c, d;
};

vector<vector<int>> parent(N + 1, vector<int>(lg + 1, 0)),
    sumd(N + 1, vector<int>(lg + 1, 0)), sumc(N + 1, vector<int>(lg + 1, 0));
vector<Road> adj[N + 5];
vector<int> depth;
int n, q, sum = 0;

void dfsSetUp(int u, int p) {
  for (auto &[v, c, d] : adj[u]) {
    if (v != p) {
      parent[v][0] = u;
      sumc[v][0] = c;
      sumd[v][0] = d;
      depth[v] = depth[u] + 1;
      dfsSetUp(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      int mid = parent[i][j - 1];
      parent[i][j] = parent[mid][j - 1];
      sumc[i][j] = sumc[i][j - 1] + sumc[mid][j - 1];
      sumd[i][j] = sumd[i][j - 1] + sumd[mid][j - 1];
    }
  }
}

int lca(int u, int v) {
  int sumDis = 0;
  bool flag = 0;
  if (depth[u] < depth[v]) {
    flag = 1;
    swap(u, v);
  }
  int x = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (x >= (1 << i)) {
      if (flag) {
        sumDis += sumd[u][i];
      } else {
        sumDis += sumc[u][i];
      }
      u = parent[u][i];
      x -= (1 << i);
    }
  }
  if (u == v) {
    return sumDis;
  }
  for (int i = lg; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      if (flag) {
        sumDis += sumd[u][i] + sumc[v][i];
      } else {
        sumDis += sumd[v][i] + sumc[u][i];
      }
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  if (flag) {
    sumDis += sumd[u][0] + sumc[v][0];
  } else {
    sumDis += sumd[v][0] + sumc[u][0];
  }
  return sumDis;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("PIRATE.INP", "r", stdin);
  freopen("PIRATE.OUT", "w", stdout);

  cin >> n;

  depth.resize(n + 1, 0);

  for (int u, v, c, d, i = 0; i < n - 1; i++) {
    cin >> u >> v >> c >> d;
    sum += (c + d);
    adj[u].push_back({v, c, d});
    adj[v].push_back({u, d, c});
  }

  dfsSetUp(1, 0);
  init();

  cin >> q;
  int u, v;
  while (q--) {
    cin >> u >> v;
    cout << sum - lca(u, v) << "\n";
  }
}
