#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
const int oo = 1e9;

int n, x, c;
vector<int> cost, sell, depth, adj[N + 5];
vector<bool> vis;

void dfs(int start) {
  stack<int> st;
  vector<int> parent(n + 1, -1);

  st.push(start);
  depth[start] = 0;

  while (!st.empty()) {
    int u = st.top();
    st.pop();

    sell[start] = max(sell[start], depth[u]);

    for (int v : adj[u]) {
      if (v == parent[u])
        continue;
      parent[v] = u;
      depth[v] = depth[u] + x;
      st.push(v);
    }
  }
}

void solve() {
  cin >> n >> x >> c;

  sell.assign(n + 1, 0);
  cost.assign(n + 1, oo);
  vis.assign(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int u, v, i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  q.push(x);
  cost[x] = 0;
  vis[x] = 1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    depth.assign(n + 1, 0);
    dfs(u);

    for (int v : adj[u]) {
      if (!vis[v] && cost[v] > cost[u] + c) {
        vis[v] = 1;
        cost[v] = cost[u] + c;
        q.push(v);
      }
    }
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, sell[i] - cost[i]);
  }

  cout << res << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
