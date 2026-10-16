#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
#define int long long
int seg[4 * N], lazy[4 * N];

void push(int id, int l, int r) {
  if (lazy[id] != 0) {
    int mid = (l + r) / 2;
    seg[id * 2] += lazy[id] * (mid - l + 1);
    seg[id * 2 + 1] += lazy[id] * (r - mid);
    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
  }
}

void update(int id, int l, int r, int u, int v, int val) {
  if (v < l || r < u)
    return;
  if (u <= l && r <= v) {
    seg[id] += (r - l + 1) * val;
    lazy[id] += val;
    return;
  }
  push(id, l, r);
  int mid = (l + r) / 2;
  update(id * 2, l, mid, u, v, val);
  update(id * 2 + 1, mid + 1, r, u, v, val);
  seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

int query(int id, int l, int r, int u, int v) {
  if (v < l || r < u)
    return 0;
  if (u <= l && r <= v)
    return seg[id];
  push(id, l, r);
  int mid = (l + r) / 2;
  return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    fill(seg, seg + 4 * n, 0);
    fill(lazy, lazy + 4 * n, 0);
    while (q--) {
      int type, l, r;
      cin >> type >> l >> r;
      l--, r--;
      if (type == 0) {
        int val;
        cin >> val;
        update(1, 0, n - 1, l, r, val);
      } else
        cout << query(1, 0, n - 1, l, r) << "\n";
    }
  }
}
