#include <bits/stdc++.h>

using namespace std;

vector<int> st;
vector<int> lazy;

void push(int id, int l, int r) {
  if (lazy[id]) {
    lazy[id] = 0;
    st[id] = r - l + 1 - st[id];
    if (l != r) {
      lazy[id * 2] ^= 1;
      lazy[id * 2 + 1] ^= 1;
    }
  }
}

void update(int node, int l, int r, int u, int v) {
  push(node, l, r);
  if (l > r || l > v || u > r)
    return;
  if (u <= l && r <= v) {
    st[node] = r - l + 1 - st[node];
    if (l != r) {
      lazy[node * 2] ^= 1;
      lazy[node * 2 + 1] ^= 1;
    }
    return;
  }
  int mid = (l + r) / 2;
  update(2 * node, l, mid, u, v);
  update(2 * node + 1, mid + 1, r, u, v);
  st[node] = st[2 * node] + st[2 * node + 1];
}

int query(int node, int start, int end, int l, int r) {
  push(node, start, end);
  if (start > r || end < l)
    return 0;
  if (l <= start && end <= r)
    return st[node];
  int mid = (start + end) / 2;
  return query(2 * node, start, mid, l, r) +
         query(2 * node + 1, mid + 1, end, l, r);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("flipcoin.inp", "r", stdin);
  freopen("flipcoin.out", "w", stdout);

  int n, q, a, x, y;
  cin >> n >> q;
  st.resize(n * 4 + 5, 0);
  lazy.resize(n * 4 + 5, 0);
  while (q--) {
    cin >> a >> x >> y;
    if (a == 0) {
      update(1, 1, n, x, y);
    } else {
      cout << query(1, 1, n, x, y) << "\n";
    }
  }
}
