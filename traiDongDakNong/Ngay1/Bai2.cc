#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 5;

vector<int> adj[MAXN];
set<int> res;
int c, n, k, cnt;

void dfs(int u, int p) {
  if (cnt == k) {
    res.insert(u);
    return;
  }
  for (auto v : adj[u]) {
    if (v != p) {
      cnt++;
      dfs(v, u);
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> c >> n >> k;
  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  sort(adj[1].begin(), adj[1].end());
  cnt = 1;
  dfs(1, 1);
  while (next_permutation(adj[1].begin(), adj[1].end())) {
    cnt = 1;
    dfs(1, 1);
  }
  for (auto i : res) {
    cout << i << " ";
  }
}
