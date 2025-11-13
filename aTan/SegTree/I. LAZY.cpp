#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> st, lazy;
int n, q;

void propag(int id, int l, int r) {
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
  propag(id, l, r);
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

  int mid = (l + r) / 2;
  update(l, mid, u, v, x, id * 2);
  update(mid + 1, r, u, v, x, id * 2 + 1);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int query(int l, int r, int u, int v, int id) {
  propag(id, l, r);
  if (l > r || l > v || u > r) {
    return LLONG_MIN;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int mid = (l + r) / 2;
  return max(query(l, mid, u, v, id * 2), query(mid + 1, r, u, v, id * 2 + 1));
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;
  st.resize(4 * n + 4);
  lazy.resize(4 * n + 4, 0);

  int type, x, y, k;
  while (q--) {
    cin >> type >> x >> y;
    if (type == 1) {
      cout << query(1, n, x, y, 1) << "\n";
    } else {
      cin >> k;
      update(1, n, x, y, k, 1);
    }
  }
}
