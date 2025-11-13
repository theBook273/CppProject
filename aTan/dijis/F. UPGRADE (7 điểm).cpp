#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int u, v, w;
};

struct Graph {
  int to, len;
};

const int MAXN = 1e5 + 5;
const int INF = 1e18;

unordered_map<int, int> mp;
vector<Graph> adj[MAXN];
vector<Edge> edge;
int dis1[MAXN], disn[MAXN], cnt1[MAXN], cntn[MAXN];
int n, m, tong = 0, total;

bool valid(int a, int b, int w) { return (dis1[a] + w + disn[b] == dis1[n]); }

void djisk(int start, int dis[], int cnt[]) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  q.push({0, start});
  dis[start] = 0;
  cnt[start] = 1;

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
        q.push({dis[v], v});
      } else if (dis[v] == dis[u] + w) {
        cnt[v] += cnt[u];
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
    edge.push_back({u, v, w});
  }

  for (int i = 1; i <= n; i++) {
    dis1[i] = INF;
    disn[i] = INF;
  }

  djisk(1, dis1, cnt1);
  djisk(n, disn, cntn);

  for (auto [u, v, w] : edge) {
    if (valid(u, v, w)) {
      tong += (cnt1[u] * cntn[v] == cnt1[n]);
    } else if (valid(v, u, w)) {
      tong += (cnt1[v] * cntn[u] == cnt1[n]);
    }
  }

  cout << tong;
}
