#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int n, sz[MAXN];

void dfs(int u, int p) {
  sz[u] = 1;
  for (auto v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  for (int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << sz[i] << "\n";
  }
}
