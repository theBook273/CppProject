#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e5 + 27;

int st[maxn * 4], a[maxn];

void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int tar, int data) {
  if (l == r) {
    st[id] = data;
    return;
  }
  int m = (l + r) / 2;
  if (tar <= m) {
    update(id * 2, l, m, tar, data);
  } else {
    update(id * 2 + 1, m + 1, r, tar, data);
  }
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int query(int id, int l, int r, int u, int v) {
  if (l > r || l > v || u > r) {
    return -1e9 + 2;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int m = (l + r) / 2;
  int left = query(id * 2, l, m, u, v);
  int right = query(id * 2 + 1, m + 1, r, u, v);
  return max(left, right);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  int q, temp, x, y;
  cin >> q;
  while (q--) {
    cin >> temp >> x >> y;
    if (temp == 1) {
      update(1, 1, n, x, y);
    } else {
      cout << query(1, 1, n, x, y) << "\n";
    }
  }
}
