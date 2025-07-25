#include <bits/stdc++.h>
#define int long long

using namespace std;

int st[9999999];
vector<int> a;

void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int l, int r, int tar, int data) {
  if (tar < l || r < tar) {
    return;
  }
  if (l == r) {
    st[id] = data;
    return;
  }
  int m = (l + r) / 2;
  update(id * 2, l, m, tar, data);
  update(id * 2 + 1, m + 1, r, tar, data);
  st[id] = st[id * 2] + st[id * 2 + 1];
}

int queries(int id, int l, int r, int u, int v) {
  if (l > v || u > r)
    return 0;
  if (u <= l && r <= v)
    return st[id];
  int m = (l + r) / 2;
  int left = queries(id * 2, l, m, u, v);
  int right = queries(id * 2 + 1, m + 1, r, u, v);
  return left + right;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  a.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  int q, x, y;
  while (k--) {
    cin >> q >> x >> y;
    if (q == 1) {
      update(1, 1, n, x, y);
    } else {
      cout << queries(1, 1, n, x, y) << "\n";
    }
  }
}
