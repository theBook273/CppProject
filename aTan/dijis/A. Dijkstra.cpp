#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 5;

struct Edge {
  int to, len;
};

vector<Edge> adj[MAXN];
int dis[MAXN];
int n, m;

void disjik(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  q.push({0, start});
  dis[start] = 0;

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != dis[u])
      continue;

    for (auto [to, len] : adj[u]) {
      if (dis[to] > dis[u] + len) {
        dis[to] = dis[u] + len;
        q.push({dis[to], to});
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for (int i = 1; i <= n; i++) {
    dis[i] = 1e9 + 5;
  }

  disjik(1);
  cout << dis[n];
}
