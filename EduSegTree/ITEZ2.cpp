#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> st, a;

void update(int id, int l, int r, int tar, int data) {
  if (l == r) {
    st[id] = data;
    return;
  }
  int m = (l + r) / 2;
  if (tar <= m) {
    update(id * 2, l, m, tar, data);
  } else {
    update(id * 2 + 1, m + 1, r, tar, data);
  }
  st[id] = st[id * 2] + st[id * 2 + 1];
}

int query(int id, int l, int r, int u, int v) {
  if (l > r || l > v || u > r) {
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
  cin.tie()->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  st.resize(n * 4 + 27, 0);
  a.resize(n + 1);
  int type, x, y;
  while (q--) {
    cin >> type >> x >> y;
    if (type == 1) {
      update(1, 1, n, x, y);
    } else {
      cout << query(1, 1, n, x, y) << "\n";
    }
  }
}
