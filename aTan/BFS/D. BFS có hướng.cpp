#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1e5 + 5;

int n, m, s, t;
vector<int> adj[MAXN];
bool vis[MAXN];
int road[MAXN];

void bfs() {
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  road[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 1;
    for (auto v : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        road[v] = road[u] + 1;
        q.push(v);
        if (v == t) {
          return;
        }
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m >> s >> t;
  memset(road, -1, sizeof(road));
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
  }

  bfs();
  cout << road[t];
}
