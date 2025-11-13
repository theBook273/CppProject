#include <bits/stdc++.h>

using namespace std;

int a[1000000];
map<int, int> st[1000000];

void build(int l, int r, int id) {
  if (l == r) {
    st[id][a[r]]++;
    return;
  }
  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);
  for (auto [i, j] : st[id * 2]) {
    st[id][i] += j;
  }
  for (auto [i, j] : st[id * 2 + 1]) {
    st[id][i] += j;
  }
}

int query(int l, int r, int u, int v, int id) {
  if (l < u || r > v) {
    return 0;
  }
  if (u <= l && r <= v) {
    int tong = 0;
    for (auto [i, j] : st[id]) {
      if (j == 2)
        tong++;
    }
    return tong;
  }
  int m = (l + r) / 2;
  map<int, int> temp;
  for (auto [i, j] : st[id * 2]) {
    temp[i] += j;
  }
  for (auto [i, j] : st[id * 2 + 1]) {
    temp[i] += j;
  }
  int tong = 0;
  for (auto [i, j] : temp) {
    if (j == 2) {
      tong++;
    }
  }
  return tong;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << query(1, n, l, r, 1) << "\n";
  }
}
