#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int from, to;
};

struct Query {
  char type;
  int x, y;
};

vector<Edge> edge;
vector<Query> query;
vector<int> dsu, a, mark, res, tong;
int n, m, q;
multiset<int> se;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }

void join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    se.erase(se.find(tong[x]));
    se.erase(se.find(tong[y]));

    dsu[y] = x;
    tong[x] += tong[y];

    se.insert(tong[x]);
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test.inp", "r", stdin);
  freopen("testChuan.out", "w", stdout);

  cin >> n >> m >> q;

  dsu.resize(n);
  a.resize(n);
  tong.resize(n);
  edge.resize(m);
  mark.resize(m, 0);
  query.resize(q);
  res.resize(q);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> edge[i].from >> edge[i].to;
    edge[i].from--;
    edge[i].to--;
  }

  for (int i = 0; i < q; i++) {
    auto &[type, x, y] = query[i];
    cin >> type;
    cin >> x;
    x--;
    if (type == 'C') {
      cin >> y;
      swap(a[x], y);
    } else {
      mark[x] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    dsu[i] = i;
    tong[i] = a[i];
    se.insert(tong[i]);
  }

  for (int i = 0; i < m; i++) {
    if (!mark[i]) {
      join(edge[i].from, edge[i].to);
    }
  }

  for (int i = q - 1; i >= 0; i--) {
    res[i] = (*(--se.end()));
    auto &[type, x, y] = query[i];
    if (type == 'D') {
      join(edge[x].from, edge[x].to);
    } else {
      int old = tong[parent(x)];

      se.erase(se.find(old));

      int now = parent(x);
      tong[now] -= a[x];
      a[x] = y;
      tong[now] += a[x];

      se.insert(tong[now]);
    }
  }

  for (auto i : res) {
    cout << i << "\n";
  }
}
