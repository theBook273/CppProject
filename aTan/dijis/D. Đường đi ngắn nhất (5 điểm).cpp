#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e17;

struct Edge {
  int to, len;
};

vector<Edge> adj[MAXN];
int n, m;
int dis[MAXN], cnt[MAXN], mn[MAXN], mx[MAXN];

void dijis(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  q.push({0, start});
  dis[start] = 0;
  cnt[start] = 1;
  mn[start] = 0;
  mx[start] = 0;

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != dis[u]) {
      continue;
    }

    for (auto [v, w] : adj[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u];
        mn[v] = mn[u] + 1;
        mx[v] = mx[u] + 1;
        q.push({dis[v], v});
      } else if (dis[v] == dis[u] + w) {
        cnt[v] = (cnt[u] + cnt[v]) % MOD;
        mn[v] = min(mn[v], mn[u] + 1);
        mx[v] = max(mx[v], mx[u] + 1);
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for (int i = 1; i <= n; i++) {
    dis[i] = INF;
  }

  dijis(1);
  if (dis[n] == INF) {
    cout << -1;
  } else {
    cout << dis[n] << " " << cnt[n] << " " << mn[n] << " " << mx[n];
  }
}
