#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

struct Edge {
  int to, len;
};
struct Road {
  int from, to, len;
};

vector<Edge> adj[MAXN];
vector<Road> construct;
vector<int> dis;
int n, m, k, s, t, res(1e9);

void dijisktra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  dis[start] = 0;
  q.push({0, start});

  while (!q.empty()) {
    auto [du, u] = q.top();
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

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k >> s >> t;
  for (int u, v, w, i(0); i < m; ++i) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  dis.assign(n + 1, 1e9);

  for (int u, v, w, i(0); i < k; ++i) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dijisktra(s);
  res = min(res, dis[t]);

  if (res == 1e9) {
    cout << -1;
  } else {
    cout << res;
  }
}
