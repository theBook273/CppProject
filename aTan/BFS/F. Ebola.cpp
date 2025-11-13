#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, k, tong = 1;
vector<int> adj[MAXN];
bool vis[MAXN];

void bfs() {
  queue<int> q;
  q.push(k);
  vis[k] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        q.push(v);
        tong++;
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> k;
  for (int sz, temp, i = 1; i <= n; i++) {
    cin >> sz;
    while (sz--) {
      cin >> temp;
      adj[i].push_back(temp);
    }
  }
  bfs();
  cout << tong << "\n";
  for (int i = 1; i <= n; i++) {
    if (vis[i]) {
      cout << i << " ";
    }
  }
}
