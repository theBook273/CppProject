#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, x, tong = 0;
bool vis[MAXN];
vector<int> adj[MAXN];

void bfs(int a) {
  queue<int> q;
  q.push(a);
  vis[a] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        q.push(v);
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m >> x;
  for (int u, v, w, i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    if (w >= x) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      bfs(i);
      tong++;
    }
  }

  cout << tong;
}
