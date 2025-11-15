#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 5e4;
const int INF = 1e18;

struct road {
  int from, to, len;
  bool operator<(const road &other) { return len < other.len; }
};

vector<road> adj;
vector<int> dis, dsu;
int n, m;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }

int kruskal(vector<road> &edge) {
  iota(dsu.begin(), dsu.end(), 0);
  int tong = 0, dem = 0;
  for (auto &[u, v, w] : edge) {
    u = parent(u);
    v = parent(v);
    if (u != v) {
      dsu[u] = v;
      tong += w;
      dem++;
    }
    if (dem == (n - 1)) {
      return tong;
    }
  }
  return -1;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test", "r", stdin);
  freopen("testTrau", "w", stdout);

  cin >> n >> m;

  dsu.resize(n + 1);
  dis.assign(n + 1, INF);
  for (int u, v, w, i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    adj.push_back({u, v, w});
    sort(adj.begin(), adj.end());
    cout << kruskal(adj) << "\n";
  }
}
