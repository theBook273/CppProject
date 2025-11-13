#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

struct Edge {
  int to, len;
};

const int MAXN = 1e5 + 273;

vector<Edge> adj[MAXN];
unordered_map<int, int> op[MAXN];
vector<int> dis;
vector<bool> check;

void bfs(int x) {
  queue<int> q;
  check[x] = 1;
  q.push(x);
  while (!q.empty()) {
    int temp = q.front();
    q.pop();
    for (auto [to, len] : adj[temp]) {
      if (!check[to]) {
        dis[to] = min(dis[temp], len);
        q.push(to);
        check[to] = 1;
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("QKGRAPH.INP", "r", stdin);
  freopen("QKGRAPH.OUT", "w", stdout);

  int n, q;
  cin >> n >> q;
  for (int u, v, c, i = 0; i < n - 1; i++) {
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  for (int dinh = 1; dinh <= n; dinh++) {
    check.assign(n + 1, 0);
    dis.assign(n + 1, 0);
    dis[dinh] = 1e9;
    bfs(dinh);
    for (int i = 1; i <= n; i++) {
      op[dinh][i] = dis[i];
    }
    op[dinh][dinh] = 0;
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << op[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  int k, u, res;
  while (q--) {
    res = 0;
    cin >> k >> u;
    for (int i = 1; i <= n; i++) {
      res += (op[i][u] >= k);
    }
    cout << res << "\n";
  }
}
