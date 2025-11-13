#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int from, to;
};

vector<Edge> edge;
vector<int> query, res, mark, dsu;
int n, m, q;

int parent(int u) { return (dsu[u] == u ? u : dsu[u] = parent(dsu[u])); }

int join(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a != b) {
    dsu[a] = b;
    return 1;
  }
  return 0;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m >> q;
  edge.resize(m + 1);
  mark.resize(m + 1, 0);
  res.resize(q + 1);
  dsu.resize(n + 1);
  query.resize(m + 1);

  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    cin >> edge[i].from >> edge[i].to;
  }

  for (int i = 1; i <= q; i++) {
    cin >> query[i];
    mark[query[i]] = 1;
  }

  for (int i = 1; i <= m; i++) {
    if (!mark[i]) {
      join(edge[i].from, edge[i].to);
    }
  }

  unordered_set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(parent(i));
  }

  int cnt = se.size();
  for (int i = q; i >= 1; i--) {
    res[i] = cnt;
    if (join(edge[query[i]].from, edge[query[i]].to)) {
      cnt--;
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << res[i] << "\n";
  }
}
