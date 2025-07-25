#include <bits/stdc++.h>

using namespace std;

int st[900000][3], lazy[900000];

void merge(int left[3], int right[3], int curr[3]) {
  curr[0] = left[0] + right[0];
  curr[1] = left[1] + right[1];
  curr[2] = left[2] + right[2];
}

void increase(int curr[3]) {
  int temp = curr[0];
  curr[0] = curr[2];
  curr[2] = curr[1];
  curr[1] = temp;
}

void push(int id) {
  if (lazy[id] != 0) {
    for (int i = 0; i < lazy[id]; ++i) {
      increase(st[id]);
    }
    lazy[id * 2] = (lazy[id] + lazy[id * 2]) % 3;
    lazy[id * 2 + 1] = (lazy[id] + lazy[id * 2 + 1]) % 3;
    lazy[id] = 0;
  }
}

void build(int id, int l, int r) {
  lazy[id] = 0;
  if (l == r) {
    st[id][0] = 1;
    st[id][1] = 0;
    st[id][2] = 0;
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  merge(st[id * 2], st[id * 2 + 1], st[id]);
}

void update(int id, int l, int r, int u, int v) {
  push(id);
  if (r < l || l > v || u > r) {
    return;
  }
  if (u <= l && r <= v) {
    increase(st[id]);
    if (l != r) {
      lazy[id * 2] = (lazy[id * 2] + 1) % 3;
      lazy[id * 2 + 1] = (lazy[id * 2 + 1] + 1) % 3;
    }
    return;
  }
  int m = (l + r) / 2;
  update(id * 2, l, m, u, v);
  update(id * 2 + 1, m + 1, r, u, v);
  merge(st[id * 2], st[id * 2 + 1], st[id]);
}

int query(int id, int l, int r, int u, int v) {
  push(id);
  if (l > r || l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id][0];
  }
  int m = (l + r) / 2;
  int left = query(id * 2, l, m, u, v);
  int right = query(id * 2 + 1, m + 1, r, u, v);
  return left + right;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  build(1, 1, n);
  int que, x, y;
  while (q--) {
    cin >> que >> x >> y;
    x++;
    y++;
    if (que == 1) {
      cout << query(1, 1, n, x, y) << "\n";
    } else {
      update(1, 1, n, x, y);
    }
  }
}
