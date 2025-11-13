#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> dsu, sz;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }

void join(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a != b) {
    if (a < b) {
      swap(a, b);
    }
    dsu[b] = a;
    sz[a] += sz[b];
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;
  sz.resize(n + 1, 1);
  dsu.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }

  char type;
  int u, v;
  while (q--) {
    cin >> type >> u;
    if (type == '?') {
      cout << sz[parent(u)] << "\n";
    } else {
      cin >> v;
      join(u, v);
    }
  }
}
