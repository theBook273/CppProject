#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> dsu, res;
int n, q;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }

signed main() {
  cin.tie()->sync_with_stdio(0);

  // freopen("test", "r", stdin);
  // freopen("testChuan", "w", stdout);

  cin >> n >> q;

  dsu.resize(n + 5, 0);
  res.resize(n + 5, 0);
  for (int i = 1; i <= n + 1; i++) {
    dsu[i] = i;
  }

  int l, r, win;
  while (q--) {
    cin >> l >> r >> win;

    int v = parent(l);
    while (v <= r) {
      if (v != win) {
        res[v] = win;
        dsu[v] = parent(v + 1);
      } else {
        v++;
      }
      v = parent(v);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
}
