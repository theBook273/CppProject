#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a, st, lazy;
int n, q, type, x, y, z;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int mid((l + r) / 2);
  build(l, mid, id * 2);
  build(mid + 1, r, id * 2 + 1);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void push(int id, int l, int r) {
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
  push(id, l, r);

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

  int mid((l + r) / 2);
  update(l, mid, u, v, x, id * 2);
  update(mid + 1, r, u, v, x, id * 2 + 1);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int queryPosNow(int l, int r, int tar, int id) {
  push(id, l, r);
  if (l == r) {
    return st[id];
  }
  int mid((l + r) / 2);
  if (tar <= mid) {
    return queryPosNow(l, mid, tar, id * 2);
  }
  return queryPosNow(mid + 1, r, tar, id * 2 + 1);
}

int query(int l, int r, int u, int v, int k, int id) {
  push(id, l, r);
  if (st[id] < k || l > r || l > v || u > r) {
    return -1;
  }

  if (l == r) {
    return l;
  }

  int mid((l + r) / 2);
  int res = query(l, mid, u, v, k, id * 2);
  if (res != -1) {
    return res;
  }
  return query(mid + 1, r, u, v, k, id * 2 + 1);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;
  a.resize(n + 1);
  st.resize(4 * n + 5);
  lazy.resize(4 * n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  while (q--) {
    cin >> type >> x >> y;
    if (type == 1) {
      int posNow = x;
      int lim = min(posNow + 100, n);
      int valNow = queryPosNow(1, n, posNow, 1);
      for (int i = 0; i < y; i++) {
        int next = query(1, n, posNow + 1, lim, valNow + 1, 1);
        if (next == -1) {
          break;
        }
        posNow = next;
        lim = min(posNow + 100, n);
        valNow = queryPosNow(1, n, posNow, 1);
      }
      cout << posNow << "\n";
    } else {
      cin >> z;
      update(1, n, x, y, z, 1);
    }
  }
}
