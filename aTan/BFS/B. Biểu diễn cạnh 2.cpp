#include <bits/stdc++.h>

using namespace std;

const int maxn = 2 * 1e5 + 2;

multiset<int> adj[maxn];

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  for (int i = 1; i <= n; i++) {
    cout << adj[i].size() << " ";
    for (auto x : adj[i]) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
