#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n, q, a[maxn], st[maxn * 4], lazy[maxn * 4];
int dem = 0;
void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }

  int mid = (l + r) / 2;
  build(l, mid, id * 2);
  build(mid + 1, r, id * 2 + 1);

  st[id] = max(st[id * 2], st[id * 2 + 1]);
}
void push(int l, int r, int id) {
  if (lazy[id] != 0) {
    st[id] += lazy[id];
  }
  if (l != r) {
    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
  }
  lazy[id] = 0;
}
void update(int l, int r, int L, int H, int d, int id) {
  push(l, r, id);
  if (H < l || L > r) {
    return;
  }
  if (L <= l && H >= r) {
    st[id] += d;
    if (l != r) {
      lazy[id * 2] += d;
      lazy[id * 2 + 1] += d;
    }
    return;
  }

  int mid = (l + r) / 2;
  update(l, mid, L, H, d, id * 2);
  update(mid + 1, r, L, H, d, id * 2 + 1);

  st[id] = max(st[id * 2], st[id * 2 + 1]);
}
int query(int l, int r, int u, int v, int vln, int id) {
  push(l, r, id);
  if (v < l || u > r || st[id] < vln) {
    return -1;
  }

  if (l == r) {
    return l;
  }

  int mid = (l + r) / 2;
  int res = query(l, mid, u, v, vln, id * 2);
  if (res == -1) {
    return query(mid + 1, r, u, v, vln, id * 2 + 1);
  } else {
    return res;
  }
}
int queryValNow(int l, int r, int tar, int id) {
  push(l, r, id);
  if (l == r) {
    return st[id];
  }

  int mid = (l + r) / 2;
  if (tar <= mid) {
    return queryValNow(l, mid, tar, id * 2);
  } else {
    return queryValNow(mid + 1, r, tar, id * 2 + 1);
  }
}

signed main() {

  freopen("test.inp", "r", stdin);
  freopen("testTrau", "w", stdout);

  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      int Posnow = x;
      int lim = min(Posnow + 100, n);
      int Valnow = queryValNow(1, n, Posnow, 1);
      for (int i = 1; i <= y; i++) {
        int next = query(1, n, Posnow + 1, lim, Valnow + 1, 1);
        if (next == -1) {
          break;
        } else {
          Posnow = next;
          lim = min(Posnow + 100, n);
          Valnow = queryValNow(1, n, Posnow, 1);
        }
      }
      cout << Posnow << "\n";
    }
    if (type == 2) {
      int m, o, p;
      cin >> m >> o >> p;
      update(1, n, m, o, p, 1);
    }
  }
}
