#include <bits/stdc++.h>

using namespace std;

const int N = 3e5;

vector<int> adj[N + 5];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("two.inp", "r", stdin);
  freopen("two.out", "w", stdout);

  int t;
  cin >> t;

  int n, m;
  cin >> n >> m;

  for (int u, v, i = 0; i < m; ++i) {
    cin >> u >> v;
    ;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  long long res(0);

  for (int i = 1; i <= n; ++i) {
    for (int &x : adj[i]) {
      res += adj[x].size() - 1;
      ;
    };
  }

  cout << res;
}
