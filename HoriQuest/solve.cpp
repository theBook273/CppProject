#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 100000;

int st[MAXN * 4], lazy[MAXN * 4];

void push(int id, int l, int r) {
  if (lazy[id] != 0) {
    st[id] += (lazy[id] * (r - l + 1));
    if (l != r) {
      lazy[id * 2] += lazy[id];
      lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
  }
}

void update(int id, int l, int r, int u, int v, int data) {
  push(id, l, r);
  if (l > v || u > r) {
    return;
  }
  if (u <= l && r <= v) {
    st[id] += (data * (r - l + 1));
    if (l != r) {
      lazy[id * 2] += data;
      lazy[id * 2 + 1] += data;
    }
    return;
  }
  int m = (l + r) / 2;
  update(id * 2, l, m, u, v, data);
  update(id * 2 + 1, m + 1, r, u, v, data);
  st[id] = st[id * 2] + st[id * 2 + 1];
}

int query(int id, int l, int r, int u, int v) {
  push(id, l, r);
  if (l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id];
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
  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n * 4; i++) {
      st[i] = 0;
      lazy[i] = 0;
    }
    while (c--) {
      int type;
      cin >> type;
      if (type == 0) {
        int p, q, v;
        cin >> p >> q >> v;
        update(1, 1, n, p, q, v);
      } else {
        int p, q;
        cin >> p >> q;
        cout << query(1, 1, n, p, q) << "\n";
      }
    }
  }
}
