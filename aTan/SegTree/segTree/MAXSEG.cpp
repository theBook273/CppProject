#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<int> a, st;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }

  int m((l + r) >> 1);
  build(l, m, (id << 1));
  build(m + 1, r, (id << 1) | 1);
  st[id] = st[(id << 1)] + st[(id << 1) | 1];
}

int query(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return 0;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
