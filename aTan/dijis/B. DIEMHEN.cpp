#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

const int MAXN = 1e5 + 5;

struct Edge {
  int to, len;
};

vector<Edge> adj[MAXN];
int disF1[MAXN], disFn[MAXN];
int n, m, k;

void dijisk(int start, int dis[]) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  fill(dis, dis + n + 1, 1e18);

  dis[start] = 0;
  q.push({0, start});
  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != dis[u]) {
      continue;
    }

    for (auto [v, w] : adj[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  dijisk(1, disF1);
  dijisk(n, disFn);

  int a, b, res = 1e18;
  while (k--) {
    res = 1e18;
    cin >> a >> b;
    for (int i = 1; i <= n; i++) {
      if (disF1[i] < 1e18 && disFn[i] < 1e18)
        res = min(res, disF1[i] * a + disFn[i] * b);
    }
    cout << res << "\n";
  }
}
