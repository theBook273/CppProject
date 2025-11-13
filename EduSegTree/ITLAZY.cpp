#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> st, a, lazy;

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

void push(int id, int l, int r) {
  if (lazy[id] != 0) {
    st[id] += lazy[id];
    if (l != r) {
      lazy[id * 2] += lazy[id];
      lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
  }
}

void update(int id, int l, int r, int u, int v, int data) {
  push(id, l, r);
  if (l > r || l > v || u > r) {
    return;
  }
  if (u <= l && r <= v) {
    st[id] += data;
    if (l != r) {
      lazy[id * 2] += data;
      lazy[id * 2 + 1] += data;
    }
    return;
  }
  int m = (l + r) / 2;
  update(id * 2, l, m, u, v, data);
  update(id * 2 + 1, m + 1, r, u, v, data);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int query(int id, int l, int r, int u, int v) {
  push(id, l, r);
  if (l > r || l > v || u > r) {
    return -(1e9 + 27);
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
  int n, q;
  cin >> n;
  st.resize(n * 4 + 27);
  lazy.resize(n * 4 + 27, 0);
  a.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  cin >> q;
  int type, x, y, val;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> x >> y >> val;
      update(1, 1, n, x, y, val);
    } else {
      cin >> x >> y;
      cout << query(1, 1, n, x, y) << "\n";
    }
  }
}
