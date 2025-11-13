#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 5 * 1e5;
int st[MAXN * 4 + 5], a[MAXN + 5];
int n, q;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = 1;
    return;
  }

  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);

  st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int l, int r, int tar, int id) {
  if (l == r) {
    st[id] = 0;
    return;
  }

  int m = (l + r) / 2;
  if (tar <= m) {
    update(l, m, tar, id * 2);
  } else {
    update(m + 1, r, tar, id * 2 + 1);
  }
  st[id] = st[id * 2] + st[id * 2 + 1];
}

int query(int l, int r, int tar, int id) {
  if (l == r)
    return l;

  int m = (l + r) / 2;

  if (st[id * 2] >= tar) {
    return query(l, m, tar, id * 2);
  } else {
    return query(m + 1, r, tar - st[id * 2], id * 2 + 1);
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  for (int temp, i = 1; i <= n; i++) {
    cin >> temp;
    int idx = query(1, n, temp, 1);
    cout << a[idx] << " ";
    update(1, n, idx, 1);
  }
}
