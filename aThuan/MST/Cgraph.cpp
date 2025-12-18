#include <bits/stdc++.h>

using namespace std;

const int maxn = 200'000 + 273;
const int maxq = 500'000 + 273;
const int lg = 20;

struct edge {
  int to, len;
};

struct query {
  int type, u, v;
};

struct Up {
  int par, mx;
};

int dsu[maxn], depth[maxn], vis[maxn];
Up up[maxn][lg];
vector<edge> adj[maxn];
vector<query> que;
int n, q;

int parent(int p) { return (dsu[p] == p) ? p : dsu[p] = parent(dsu[p]); }

bool join(int u, int v) {
  u = parent(u);
  v = parent(v);
  if (u == v)
    return 0;
  dsu[u] = v;
  return 1;
}

void dfs(int u, int p) {
  vis[u] = 1;
  for (auto i : adj[u]) {
    int v = i.to;
    int c = i.len;
    if (v == p)
      continue;
    depth[v] = depth[u] + 1;
    up[v][0].par = u;
    up[v][0].mx = c;
    dfs(v, u);
  }
}

void build() {
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      up[i][0].par = i;
      dfs(i, i);
    }
  }
  for (int j = 1; j < lg; j++) {
    for (int i = 1; i <= n; i++) {
      up[i][j].par = up[up[i][j - 1].par][j - 1].par;
      up[i][j].mx = max(up[i][j - 1].mx, up[up[i][j - 1].par][j - 1].mx);
    }
  }
}

int LCA(int u, int v) {
  int ans = 0;
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int k = depth[u] - depth[v];
  for (int i = lg - 1; i >= 0; i--) {
    if (k & (1 << i)) {
      ans = max(ans, up[u][i].mx);
      u = up[u][i].par;
    }
  }
  if (u == v) {
    return ans;
  }
  for (int i = lg - 1; i >= 0; i--) {
    if (up[u][i].par != up[v][i].par) {
      ans = max({ans, up[u][i].mx, up[v][i].mx});
      u = up[u][i].par;
      v = up[v][i].par;
    }
  }
  return max({ans, up[u][0].mx, up[v][0].mx});
}

signed main() {
  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }

  que.push_back({0, 0, 0});

  for (int type, u, v, i = 1; i <= q; i++) {
    cin >> type >> u >> v;
    que.push_back({type, u, v});
    if (que[i].type == 1) {
      if (join(u, v)) {
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
      }
    }
  }

  build();

  for (int i = 1; i <= q; i++) {
    if (que[i].type == 2) {
      int ans = LCA(que[i].u, que[i].v);
      if (ans > i || parent(que[i].u) != parent(que[i].v)) {
        cout << -1;
      } else
        cout << ans;
      cout << "\n";
    }
  }
}
