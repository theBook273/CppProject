#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

vector<int> dis, adj[N + 5];
int n;

void bfs(int a) {
  queue<int> q;
  q.push(a);
  dis[a] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (!dis[v] && v != a) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dis.assign(n + 1, 0);
  bfs(1);
  int maxi, u;
  maxi = u = 0;
  for (int i = 1; i <= n; i++) {
    if (maxi < dis[i]) {
      maxi = dis[i];
      u = i;
    }
  }

  dis.assign(n + 1, 0);
  bfs(u);
  maxi = 0;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, dis[i]);
  }

  cout << maxi;
}
