#include <bits/stdc++.h>

using namespace std;

vector<int> a, st, lazy;
int n, q, type, x, y, k;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);
  st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void down(int id, int l, int r) {
  if (lazy[id]) {
    st[id] += lazy[id];
    if (l != r) {
      lazy[id * 2] += lazy[id];
      lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
  }
}

void update(int l, int r, int u, int v, int x, int id) {
  down(id, l, r);
  if (l > r || l > v || u > r) {
    return;
  }
  if (u <= l && r <= v) {
    st[id] += x;
    if (l != r) {
      lazy[id * 2] += x;
      lazy[id * 2 + 1] += x;
    }
    return;
  }
  int m = (l + r) / 2;
  update(l, m, u, v, x, id * 2);
  update(m + 1, r, u, v, x, id * 2 + 1);
  st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int goLeft(int l, int r, int u, int v, int x, int id) {
  down(id, l, r);
  if (st[id] > x || l > r || l > v || u > r) {
    return -1;
  }
  if (l == r) {
    return l;
  }
  int m = (l + r) / 2;
  int res = goLeft(l, m, u, v, x, id * 2);
  if (res != -1) {
    return res;
  }
  return goLeft(m + 1, r, u, v, x, id * 2 + 1);
}

int goRight(int l, int r, int u, int v, int x, int id) {
  down(id, l, r);
  if (st[id] > x || l > r || l > v || u > r) {
    return -1;
  }
  if (l == r) {
    return l;
  }
  int m = (l + r) / 2;
  int res = goRight(m + 1, r, u, v, x, id * 2 + 1);
  if (res != -1) {
    return res;
  }
  return goRight(l, m, u, v, x, id * 2);
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);

  cin >> n >> q;
  a.resize(n + 1), st.resize(4 * n + 5), lazy.resize(4 * n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);

  while (q--) {
    cin >> type >> x >> y >> k;
    if (type == 2) {
      cout << goLeft(1, n, x, y, k, 1) << " " << goRight(1, n, x, y, k, 1)
           << "\n";
    } else {
      update(1, n, x, y, k, 1);
    }
  }
}
