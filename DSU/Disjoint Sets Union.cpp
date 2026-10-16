#include <bits/stdc++.h>

using namespace std;

vector<int> dsu;

int parent(int x) {
  if (dsu[x] == x) {
    return x;
  } else {
    return dsu[x] = parent(dsu[x]);
  }
}

void join(int u, int v) {
  u = parent(u);
  v = parent(v);
  if (u != v) {
    dsu[v] = u;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  dsu.push_back(0);
  for (int i = 1; i <= n; i++) {
    dsu.push_back(i);
  }

  string type;
  int u, v;
  while (q--) {
    cin >> type >> u >> v;
    if (type == "union") {
      join(u, v);
    } else if (type == "get") {
      if (parent(u) == parent(v)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
