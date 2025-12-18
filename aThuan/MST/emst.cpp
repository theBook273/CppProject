#include <bits/stdc++.h>
#define int long long

using namespace std;

struct graph {
  int to, len;
};

struct edge {
  int u, v, w, id;
  bool operator<(const edge &other) const { return w < other.w; }
};

struct Up {
  int par, mx;
};

const int maxn = 2 * 1e5 + 273;
const int lg = 20;

vector<graph> adj[maxn];
vector<edge> ed;
int dsu[maxn], depth[maxn];
Up up[maxn][lg];

int parent(int p) { return ((dsu[p] == p) ? p : dsu[p] = parent(dsu[p])); }

bool join(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a == b) {
    return 0;
  }
  dsu[a] = b;
  return 1;
}

void dfs(int u, int p) {
  for (auto [to, len] : adj[u]) {
    if (to == p)
      continue;
    depth[to] = depth[u] + 1;
    up[to][0].par = u;
    up[to][0].mx = len;
    for (int i = 1; i < lg; i++) {
      up[to][i].par = up[up[to][i - 1].par][i - 1].par;
      up[to][i].mx = max(up[to][i - 1].mx, up[up[to][i - 1].par][i - 1].mx);
    }
    dfs(to, u);
  }
}

int maxEdge(int u, int v) {
  int ans = 0;

  if (depth[u] < depth[v])
    swap(u, v);

  int k = depth[u] - depth[v];
  for (int i = lg - 1; i >= 0; i--) {
    if (k & (1 << i)) {
      ans = max(ans, up[u][i].mx);
      u = up[u][i].par;
    }
  }

  if (u == v)
    return ans;

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
  cin.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }

  for (int u, v, len, i = 0; i < m; i++) {
    cin >> u >> v >> len;
    ed.push_back({u, v, len, i});
  }

  sort(ed.begin(), ed.end());

  int cntE = 0, tong = 0;
  unordered_set<int> se;

  for (auto [u, v, w, id] : ed) {
    if (join(u, v)) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      cntE++;
      tong += w;
      se.insert(id);
      if (cntE == n - 1) {
        break;
      }
    }
  }

  depth[1] = 0;
  dfs(1, 0);

  vector<int> ans(m);
  for (auto [u, v, len, id] : ed) {
    if (se.count(id)) {
      ans[id] = tong;
    } else {
      int mx = maxEdge(u, v);
      ans[id] = tong - mx + len;
    }
  }

  for (auto i : ans) {
    cout << i << "\n";
  }
}
