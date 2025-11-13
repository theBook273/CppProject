#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e18;
const int MAXN = 1e4 + 5;

struct Graph {
  int to, len;
};

vector<Graph> adj[MAXN], adjr[MAXN];
int disS[MAXN], disT[MAXN];
int n, m, k, s, t, ans;

void dijis(int start, int dis[], vector<Graph> adj[]) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  q.push({0, start});
  dis[start] = 0;

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

void solve() {
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    adjr[i].clear();
  }

  cin >> n >> m >> k >> s >> t;
  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adjr[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) {
    disS[i] = disT[i] = INF;
  }

  dijis(s, disS, adj);
  dijis(t, disT, adjr);
  ans = disS[t];

  for (int u, v, w, i = 0; i < k; i++) {
    cin >> u >> v >> w;
    if (disS[u] != INF && disT[v] != INF)
      ans = min(ans, disS[u] + w + disT[v]);
    if (disS[v] != INF && disT[u] != INF)
      ans = min(ans, disS[v] + w + disT[u]);
  }

  if (ans == INF) {
    cout << "-1\n";
  } else {
    cout << ans << "\n";
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
