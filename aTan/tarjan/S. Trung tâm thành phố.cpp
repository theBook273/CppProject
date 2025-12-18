#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5;

int n, m, timer = 0, res = 0, cen = 1, p = 0;
vector<int> id, low;
vector<pair<int, int>> adj[N + 5];

void tarjan(int u, int lastEd) {
  id[u] = low[u] = ++timer;
  int vung = (lastEd != -1);

  for (auto [v, ed] : adj[u]) {
    if (ed == lastEd) {
      continue;
    }

    if (id[v]) {
      low[u] = min(low[u], id[v]);
    }

    else {
      tarjan(v, ed);
      low[u] = min(low[u], low[v]);
      if (low[v] >= id[u]) {
        vung++;
      }
    }
  }

  if (vung > res) {
    res = vung;
    cen = u;
  }
  if (vung == res) {
    cen = min(u, cen);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  id.resize(n + 1, 0);
  low.resize(n + 1, 0);

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  for (int i = 1; i <= n; i++) {
    if (!id[i]) {
      tarjan(i, -1);
      p++;
    }
  }

  cout << res + p - 1 << " " << cen;
}
