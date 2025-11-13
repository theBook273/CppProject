#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5;

int st[4 * MAXN + 5];

void update(int l, int r, int tar, int x, int id) {
  if (l == r) {
    st[id] += x;
    return;
  }

  int m = (l + r) / 2;
  if (tar <= m) {
    update(l, m, tar, x, id * 2);
  } else {
    update(m + 1, r, tar, x, id * 2 + 1);
  }

  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int query(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return -1e18;
  }

  if (u <= l && r <= v) {
    return st[id];
  }

  int m = (l + r) / 2;

  int left = query(l, m, u, v, id * 2);
  int right = query(m + 1, r, u, v, id * 2 + 1);

  return max(left, right);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i <= n * 4; i++) {
    st[i] = 0;
  }

  int type, a, b;
  while (q--) {
    cin >> type >> a >> b;
    if (type == 0) {
      update(1, n, a, b, 1);
    } else {
      cout << query(1, n, a, b, 1) << "\n";
    }
  }
}
