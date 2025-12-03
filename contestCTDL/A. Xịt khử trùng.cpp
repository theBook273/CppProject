#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, q, k;
vector<int> a;

namespace sub1 {

signed solve() {
  int type, x, y;
  while (q--) {
    cin >> type >> x >> y;
    if (type == 1) {
      a[x] = y;
    } else if (type == 2) {
      for (int i = x; i <= y; i++) {
        a[i] /= k;
      }
    } else {
      int tong = 0;
      for (int i = x; i <= y; i++) {
        tong += a[i];
      }
      cout << tong << "\n";
    }
  }

  return 0;
}

} // namespace sub1

namespace sub2 {

vector<int> st;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int m((l + r) >> 1);
  build(l, m, (id << 1));
  build(m + 1, r, (id << 1) | 1);
  st[id] = st[id << 1] + st[(id << 1) | 1];
}

void update(int l, int r, int pos, int x, int id) {
  if (l == r) {
    st[id] = x;
    return;
  }
  int m((l + r) >> 1);
  if (pos <= m) {
    update(l, m, pos, x, (id << 1));
  } else {
    update(m + 1, r, pos, x, (id << 1) | 1);
  }
  st[id] = st[id << 1] + st[(id << 1) | 1];
}

int query(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int m((l + r) >> 1);
  int left = query(l, m, u, v, id << 1);
  int right = query(m + 1, r, u, v, (id << 1) | 1);
  return left + right;
}

signed solve() {
  st.resize(4 * n + 5, 0);

  build(1, n, 1);

  int type, x, y;
  while (q--) {
    cin >> type >> x >> y;
    if (type == 1) {
      update(1, n, x, y, 1);
    } else if (type == 2) {
      continue;
    } else {
      cout << query(1, n, x, y, 1) << "\n";
    }
  }

  return 0;
}

} // namespace sub2

namespace sub3 {

vector<int> st, lazy;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int m((l + r) >> 1);
  build(l, m, (id << 1));
  build(m + 1, r, (id << 1) | 1);
  st[id] = st[id << 1] + st[(id << 1) | 1];
}

void push(int id, int l, int r) {
  if (lazy[id] == 1) {
    st[id] = 0;
    if (l != r) {
      lazy[(id << 1)] = 1;
      lazy[(id << 1) | 1] = 1;
    }
    lazy[id] = 0;
  }
}

void update(int l, int r, int pos, int x, int id) {
  push(id, l, r);
  if (l == r) {
    st[id] = x;
    return;
  }
  int m((l + r) >> 1);
  if (pos <= m) {
    update(l, m, pos, x, (id << 1));
  } else {
    update(m + 1, r, pos, x, (id << 1) | 1);
  }
  st[id] = st[id << 1] + st[(id << 1) | 1];
}

int query(int l, int r, int u, int v, int id) {
  push(id, l, r);
  if (l > r || l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int m((l + r) >> 1);
  int left = query(l, m, u, v, id << 1);
  int right = query(m + 1, r, u, v, (id << 1) | 1);
  return left + right;
}

signed solve() {
  st.resize(4 * n + 5, 0);
  lazy.resize(4 * n + 5, 0);

  build(1, n, 1);

  int type, x, y;
  while (q--) {
    cin >> type >> x >> y;
    if (type == 1) {
      update(1, n, x, y, 1);
    } else if (type == 2) {
      for (int i = x; i <= y; i++) {
        a[i] /= k;
        update(1, n, i, a[i], 1);
      }
    } else {
      cout << query(1, n, x, y, 1) << "\n";
    }
  }

  return 0;
}

} // namespace sub3

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("spray.inp", "r", stdin);
  freopen("spray.out", "w", stdout);

  cin >> n >> q >> k;

  a.resize(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (max(n, q) <= 3000) {
    return sub1::solve();
  }
  if (k == 1) {
    return sub2::solve();
  }
  bool flag = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > 1) {
      flag = 0;
      break;
    }
  }
  return sub3::solve();
}
