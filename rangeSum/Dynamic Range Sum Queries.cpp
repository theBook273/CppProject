#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a, st, lazy;

void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    lazy[id] = 0;
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
}

void push(int id, int l, int r) {
  if (lazy[id] != 0) {
    if (l == r) {
      st[id] += lazy[id];
    } else {
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
    if (l == r) {
      st[id] += data;
    } else {
      lazy[id] += data;
    }
    return;
  }
  int m = (l + r) / 2;
  update(id * 2, l, m, u, v, data);
  update(id * 2 + 1, m + 1, r, u, v, data);
}

int query(int id, int l, int r, int tar) {
  push(id, l, r);
  if (l > r || l > tar || tar > r) {
    return 0;
  }
  if (l == r) {
    return st[id];
  }
  int m = (l + r) / 2;
  int left = query(id * 2, l, m, tar);
  int right = query(id * 2 + 1, m + 1, r, tar);
  return left + right;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cout.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  st.resize(n * 4 + 27);
  lazy.resize(n * 4 + 27);
  build(1, 1, n);
  int x, y, z, up;
  while (m--) {
    cin >> x;
    if (x == 2) {
      cin >> y;
      cout << query(1, 1, n, y) << "\n";
    } else {
      cin >> y >> z >> up;
      update(1, 1, n, y, z, up);
    }
  }
}
