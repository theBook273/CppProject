#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;
const int oo = 1e18;

int n, m, c;
vector<pair<int, int>> radj[N + 5], adj[N + 5];
vector<int> dis;

void dijiskNor(int start) {
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

void revDisjk(vector<int> &start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  for (auto i : start) {
    q.push({dis[i], i});
  }

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != dis[u]) {
      continue;
    }

    for (auto [v, w] : radj[u]) {
      if (dis[v] > dis[u] + w + c) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> c;

  dis.resize(n + 1, oo);

  for (int u, v, w, wx, i = 0; i < m; i++) {
    cin >> u >> v >> w >> wx;
    adj[u].push_back({v, w});
    radj[v].push_back({u, wx});
  }

  dijiskNor(1);

  if (dis[n] != oo) {
    cout << dis[n];
    return 0;
  }

  vector<int> startPoint;
  for (int i = 1; i <= n; i++) {
    if (dis[i] != oo) {
      startPoint.push_back(i);
    }
  }

  revDisjk(startPoint);

  if (dis[n] != oo) {
    cout << c + dis[n];
  } else {
    cout << -1;
  }
}
