#include <bits/stdc++.h>

using namespace std;

vector<int> st, a;
int n, q;

void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int x) {
  if (l == r) {
    st[id] = x;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) {
    update(id * 2, l, mid, pos, x);
  } else {
    update(id * 2 + 1, mid + 1, r, pos, x);
  }
  st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int queryL(int id, int l, int r, int u, int v, int k) {
  if (st[id] > k || l > r || l > v || u > r) {
    return -1;
  }
  if (l == r) {
    return l;
  }

  int mid = (l + r) / 2;

  int res = queryL(id * 2, l, mid, u, v, k);
  if (res != -1)
    return res;
  else
    return queryL(id * 2 + 1, mid + 1, r, u, v, k);
}

int queryR(int id, int l, int r, int u, int v, int k) {
  if (st[id] > k || l > r || l > v || u > r) {
    return -1;
  }
  if (l == r) {
    return l;
  }

  int mid = (l + r) / 2;

  int res = queryR(id * 2 + 1, mid + 1, r, u, v, k);
  if (res != -1)
    return res;
  else
    return queryR(id * 2, l, mid, u, v, k);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;
  a.resize(n + 1), st.resize(4 * n + 4);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, 1, n);

  int type, x, y, k;
  while (q--) {
    cin >> type >> x >> y;
    if (type == 1) {
      update(1, 1, n, x, y);
    } else {
      cin >> k;
      cout << queryL(1, 1, n, x, y, k) << " " << queryR(1, 1, n, x, y, k)
           << "\n";
    }
  }
}
