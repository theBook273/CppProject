#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e18;

vector<int> dsu;
vector<bool> vis;
vector<pair<int, int>> adj[505];
int n, m, minWei = 0, edCnt = 0, maxEdge, endFound;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }

bool dfsFind(int u, int tar, int curMax, int &bestU, int &bestV) {
  if (u == tar) {
    maxEdge = curMax;
    endFound = 1;
    return 1;
  }

  vis[u] = 1;
  for (auto &[v, w] : adj[u]) {
    if (!vis[v]) {
      int newU = bestU, newV = bestV, newMax = curMax;

      if (w > newMax) {
        newMax = w;
        newU = u;
        newV = v;
      }

      if (dfsFind(v, tar, newMax, newU, newV)) {
        bestU = newU;
        bestV = newV;
        return 1;
      }
    }
  }

  return 0;
}

void removeEdge(int u, int v, int w) {
  for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
    if (it->first == v && it->second == w) {
      adj[u].erase(it);
      return;
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test", "r", stdin);
  freopen("testChuan", "w", stdout);

  cin >> n >> m;
  dsu.resize(n + 1);
  vis.resize(n + 1, 0);
  iota(dsu.begin(), dsu.end(), 0);

  for (int u, v, w, i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    int pu = parent(u);
    int pv = parent(v);
    if (pu != pv) {
      dsu[pu] = pv;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      edCnt++;
      minWei += w;
    } else {
      fill(vis.begin(), vis.end(), 0);
      endFound = 0;
      maxEdge = -INF;

      int toRU = u, toRV = u;

      dfsFind(u, v, 0, toRU, toRV);

      if (endFound && maxEdge > w) {
        removeEdge(toRU, toRV, maxEdge);
        removeEdge(toRV, toRU, maxEdge);

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        minWei -= (maxEdge - w);
      }
    }

    cout << ((edCnt == (n - 1)) ? minWei : -1) << "\n";
  }
}
