#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1e5 + 5;

int n, m, s, tong = 1;
vector<int> adj[MAXN];
bool vis[MAXN];

void bfs() {
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 1;
    for (auto v : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        tong++;
        q.push(v);
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m >> s;
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bfs();
  cout << tong;
}
