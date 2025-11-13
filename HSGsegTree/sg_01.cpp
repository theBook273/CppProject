#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 273;

int st[4 * maxn], a[maxn];

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }

  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);

  st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int l, int r, int tar, int x, int id) {
  if (l > tar || r < tar) {
    return;
  }

  if (l == r && l == tar) {
    st[id] = x;
    return;
  }

  int m = (l + r) / 2;
  update(l, m, tar, x, id * 2);
  update(m + 1, r, tar, x, id * 2 + 1);

  st[id] = st[id * 2] + st[id * 2 + 1];
}

int query(int l, int r, int u, int v, int id) {
  if (l > v || u > r) {
    return 0;
  }

  if (u <= l && r <= v) {
    return st[id];
  }

  int m = (l + r) / 2;
  int lef = query(l, m, u, v, id * 2);
  int ri = query(m + 1, r, u, v, id * 2 + 1);

  return lef + ri;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  int type, x, y;
  while (q--) {
    cin >> type >> x >> y;
    if (type == 1) {
      update(1, n, x, y, 1);
    } else {
      cout << query(1, n, x, y, 1) << "\n";
    }
  }
}
