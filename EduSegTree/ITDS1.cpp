#include <bits/stdc++.h>
#define int long long

using namespace std;
const int inf = 1e9 + 27;

vector<int> st, a;

void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  st[id] = min(st[id * 2], st[id * 2 + 1]);
}

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
  st[id] = min(st[id * 2], st[id * 2 + 1]);
}

// int query(int id, int l, int r, int u, int v, int tar) {
//   if (l > r || l > v || u > r) {
//     return inf;
//   }
//   if (st[id] >= tar) {
//     return st[id];
//   }
//   if (l == r) {
//     return inf;
//   }
//   int m = (l + r) / 2;
//   int left = query(id * 2, l, m, u, v, tar);
//   int right = query(id * 2 + 1, m + 1, r, u, v, tar);
//   return min(left, right);
// }
int query(int id, int l, int r, int u, int v, int tar) {
  if (r < u || l > v) {
    return inf;
  }
  if (st[id] >= tar) {
    return st[id];
  }
  if (l == r) {
    return inf;
  }
  int m = (l + r) / 2;
  int res_left = query(id * 2, l, m, u, v, tar);
  int res_right = query(id * 2 + 1, m + 1, r, u, v, tar);
  return min(res_left, res_right);
}

signed main() {
  int n, m;
  cin >> n >> m;
  st.resize(n * 4 + 27);
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  int type, l, r, x;
  while (m--) {
    cin >> type;
    if (type == 1) {
      cin >> l >> x;
      update(1, 1, n, l, x);
    } else {
      cin >> l >> r >> x;
      int res = query(1, 1, n, l, r, x);
      cout << (res == inf ? -1 : res) << "\n";
    }
  }
}
