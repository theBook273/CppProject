#include <bits/stdc++.h>

using namespace std;

string res[] = {"NO\n", "YES\n"};
vector<int> dsu;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }

void join(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a != b) {
    dsu[a] = b;
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  dsu.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }

  char type;
  int u, v;
  while (q--) {
    cin >> type >> u >> v;
    if (type == '+') {
      join(u, v);
    } else {
      cout << res[parent(u) == parent(v)];
    }
  }
}
