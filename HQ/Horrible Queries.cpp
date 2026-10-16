#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> st;
vector<int> lazy;

void push(int id, int l, int r) {
  if (lazy[id]) {
    st[id] += lazy[id] * (r - l + 1);
    if (l != r) {
      lazy[id * 2] += lazy[id];
      lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
  }
}

void update(int id, int l, int r, int u, int v, int val) {
  push(id, l, r);
  if (l > r || l > v || u > r)
    return;
  if (u <= l && r <= v) {
    st[id] += val * (r - l + 1);
    if (l != r) {
      lazy[id * 2] += val;
      lazy[id * 2 + 1] += val;
    }
    return;
  }
  int mid = (l + r) / 2;
  update(id * 2, l, mid, u, v, val);
  update(id * 2 + 1, mid + 1, r, u, v, val);
  st[id] = st[id * 2] + st[id * 2 + 1];
}

int query(int id, int l, int r, int u, int v) {
  push(id, l, r);
  if (l > r || l > v || u > r)
    return 0;
  if (u <= l && r <= v) {
    return st[id];
  }
  int mid = (l + r) / 2;
  int left = query(id * 2, l, mid, u, v);
  int right = query(id * 2 + 1, mid + 1, r, u, v);
  return left + right;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n, q, x, a, b, c;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    st.assign(n * 4 + 5, 0);
    lazy.assign(n * 4 + 5, 0);
    while (q--) {
      cin >> x;
      if (x == 0) {
        cin >> a >> b >> c;
        update(1, 1, n, a, b, c);
      } else {
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << "\n";
      }
    }
  }
}
