#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e4 + 273;
const int lg = 20;

int dsu[maxn], depth[maxn], talk[maxn], up[maxn][lg];
vector<pair<int, int>> adj[maxn];
vector<pair<int, pair<int, int>>> edge;

int acs(int p) { return (dsu[p] == p ? p : dsu[p] = acs(dsu[p])); };

bool join(int a, int b) {
  a = acs(a);
  b = acs(b);
  if (a == b)
    return 0;
  dsu[a] = b;
  return 1;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    cin >> talk[i];
  }

  for (int u, v, len, i = 1; i <= m; i++) {
    cin >> u >> v >> len;
    len = len * 2 + talk[u] + talk[v];
    edge.push_back({len, {u, v}});
  }

  sort(edge.begin(), edge.end());

  int tong = 0;
  int cnt = 0;
  for (auto [len, fromTo] : edge) {
    int u = fromTo.first;
    int v = fromTo.second;
    if (join(u, v)) {
      adj[u].push_back({v, len});
      adj[v].push_back({u, len});
      cnt++;
      tong += len;
      if (cnt == n - 1)
        break;
    }
  }

  cout << tong + *min_element(talk + 1, talk + n + 1) << "\n";
}
