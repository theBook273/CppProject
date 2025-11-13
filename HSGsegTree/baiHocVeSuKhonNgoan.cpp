#include <bits/stdc++.h>

using namespace std;

struct people {
  unordered_map<int, int> mp;
};

const int MAXN = 5 * 1e5 + 273;

people st[4 * MAXN];
int a[MAXN];

void build(int l, int r, int id) {
  if (l == r) {
    st[id].mp[a[l]]++;
    return;
  }
  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);
  for (auto [i, j] : st[id * 2].mp) {
    st[id].mp[i] += j;
  }
  for (auto [i, j] : st[id * 2 + 1].mp) {
    st[id].mp[i] += j;
  }
}

people query(int l, int r, int u, int v, int id) {
  if (l > v || u > r)
    return {};

  if (u <= l && r <= v)
    return st[id];

  int m = (l + r) / 2;
  people left = query(l, m, u, v, id * 2);
  people right = query(m + 1, r, u, v, id * 2 + 1);

  people res;
  for (auto [i, j] : left.mp)
    res.mp[i] += j;
  for (auto [i, j] : right.mp)
    res.mp[i] += j;
  return res;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  int l, r, res = 0;
  while (m--) {
    res = 0;
    cin >> l >> r;
    for (auto [i, j] : query(1, n, l, r, 1).mp) {
      if (j == 2) {
        res++;
      }
    }
    cout << res << "\n";
  }
}
