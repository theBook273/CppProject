#include <bits/stdc++.h>

using namespace std;

class solution {
private:
  vector<int> dis;
  vector<pair<int, int>> adj[100005];
  int n, m, a, b;

  void disjik(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, start});
    dis[start] = 0;

    while (!q.empty()) {
      int du = q.top().first;
      int u = q.top().second;
      q.pop();

      if (du != dis[u]) {
        continue;
      }

      for (auto [to, len] : adj[u]) {
        if (dis[to] > dis[u] + len) {
          dis[to] = dis[u] + len;
          q.push({dis[to], to});
        }
      }
    }
  }

public:
  void solve() {
    cin >> n >> m;
    for (int u, v, w, i = 0; i < m; i++) {
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
    }

    for (int i = 0; i <= n + 1; i++) {
      dis.push_back(1e9 + 5);
    }

    cin >> a >> b;
    disjik(a);
    cout << ((dis[b] != 1e9 + 5) ? to_string(dis[b]) : "NO") << "\n";
  }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solution now;
    now.solve();
  }
}
