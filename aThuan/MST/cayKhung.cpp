#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2 * 1e5 + 273;

unordered_map<int, int> mp[maxn];
unordered_set<int> vis;
int n, m;

void dfs(int u) {
  unordered_set<int> toRe;
  for (int i : vis) {
    if (!mp[u][i]) {
      toRe.insert(i);
    }
  }

  for (auto i : toRe) {
    vis.erase(i);
  }

  for (auto i : toRe) {
    dfs(i);
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    vis.insert(i);
  }

  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    mp[u][v] = 1;
    mp[v][u] = 1;
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (vis.count(i)) {
      res++;
      dfs(i);
    }
  }

  cout << res - 1;
}
