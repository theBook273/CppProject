#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

int n, k, timer = 0;
vector<int> tin, pos, tout, adj[N + 5];

void dfs(int u, int p) {
  tin[u] = ++timer;
  pos[timer] = u;
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  tout[u] = timer;
}

int dem(int x) {
  int res = 0;
  for (int i(tin[x] + 1); i <= tout[x]; ++i) {
    res += (abs(pos[i] - x) <= k);
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  tin.resize(N + 5, 0);
  tout.resize(N + 5, 0);
  pos.resize(N + 5, 0);

  cin >> n >> k;

  set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(i);
  }

  for (int u, v, i(0); i < n - 1; ++i) {
    cin >> u >> v;
    se.erase(se.find(v));
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(*se.begin(), -1);

  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += dem(i);
  }
  cout << res;
}
