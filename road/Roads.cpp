#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

class solution {
private:
  struct Edge {
    int to, len, mon;
  };

  vector<Edge> adj[MAXN];
  vector<vector<int>> spent;
  int n, m, k;

  int djisk(int start, int tar) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        q;
    q.push({0, 0, start});
    while (!q.empty()) {
      auto [len, cos, u] = q.top();
      q.pop();

      if (cos > k) {
        continue;
      }

      if (u == tar) {
        return len;
      }

      bool dom = 0;
      for (int c2 : spent[u]) {
        if (c2 <= cos) {
          dom = 1;
          break;
        }
      }
      if (dom) {
        continue;
      }

      spent[u].push_back(cos);

      for (auto &e : adj[u]) {
        int nc = cos + e.mon;
        if (nc > k) {
          continue;
        }
        q.push({len + e.len, nc, e.to});
      }
    }
    return -1;
  }

public:
  void solve() {
    cin >> k >> n >> m;
    for (int u, v, w, c, i = 0; i < m; ++i) {
      cin >> u >> v >> w >> c;
      adj[u].push_back({v, w, c});
    }

    spent.assign(n + 1, {});
    cout << djisk(1, n) << "\n";
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
