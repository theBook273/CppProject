#include <algorithm>
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;

int n, q, timer = 0;
vector<int> depth, tin, tout, pos, adj[N + 5], dpos[N + 5];

void dfs(int u, int p) {
  tin[u] = ++timer;
  pos[timer] = u;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }

    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
  tout[u] = timer;
}

int get(int u, int d) {
  int l = tin[u];
  int r = tout[u];

  auto &vec = dpos[d];
  return upper_bound(vec.begin(), vec.end(), r) -
         lower_bound(vec.begin(), vec.end(), l);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  tin.resize(N + 1, 0);
  tout.resize(N + 1, 0);
  pos.resize(N + 1, 0);
  depth.resize(N + 1, 0);

  cin >> n;
  for (int u, i = 2; i <= n; i++) {
    cin >> u;
    adj[u].push_back(i);
    adj[i].push_back(u);
  }

  dfs(1, -1);

  for (int i = 1; i <= n; i++) {
    dpos[depth[i]].push_back(tin[i]);
  }
  for (int i = 1; i <= n; i++) {
    sort(dpos[i].begin(), dpos[i].end());
  }

  cin >> q;
  int u, d;
  while (q--) {
    cin >> u >> d;
    cout << get(u, d) << "\n";
  }
}
