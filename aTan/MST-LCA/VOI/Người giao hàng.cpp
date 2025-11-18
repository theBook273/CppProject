#include <bits/stdc++.h>
#include <cstdio>
#include <utility>
#define int long long

using namespace std;

const int N = 2e5;
const int lg = 20;
const int oo = 1e18;

vector<vector<int>> parent(N + 5, vector<int>(lg + 5, 0)),
    maxP(N + 5, vector<int>(lg + 5, -oo));
vector<int> a, depth, dp, adj[N + 5];
vector<bool> able;
int n, k;

void dfsSetUp(int u, int p) {
  for (auto &v : adj[u]) {
    if (v != p) {
      parent[v][0] = u;
      maxP[v][0] = a[v];
      depth[v] = depth[u] + 1;
      dfsSetUp(v, u);
    }
  }
}

void init() {
  for (int j = 1; j <= lg; j++) {
    for (int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
      maxP[i][j] = max(maxP[i][j - 1], maxP[parent[i][j - 1]][j - 1]);
    }
  }
}

int maxBetween(int u, int v) {
  if (u == v) {
    return a[u];
  }
  int maxi = -oo;
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int x = depth[u] - depth[v];
  for (int i = lg; i >= 0; i--) {
    if (x >= (1 << i)) {
      maxi = max(maxi, maxP[u][i]);
      u = parent[u][i];
      x -= (1 << i);
    }
  }
  if (u == v) {
    return max(maxi, a[u]);
  }
  for (int i = lg; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      maxi = max({maxi, maxP[u][i], maxP[v][i]});
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  return max({maxi, maxP[u][0], maxP[v][0], a[parent[u][0]]});
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("SHIP.inp", "r", stdin);
  freopen("SHIP.out", "w", stdout);

  cin >> n;

  depth.resize(n + 1, 0), a.resize(n + 1), dp.resize(n + 1, -oo);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  maxP[1][0] = a[1];
  dfsSetUp(1, -1);
  init();

  cin >> k;
  int x, y;
  dp[1] = 0;
  while (k--) {
    cin >> x >> y;
    dp[y] = max(dp[y], dp[x] + maxBetween(x, y));
  }

  cout << *max_element(dp.begin(), dp.end());
}
