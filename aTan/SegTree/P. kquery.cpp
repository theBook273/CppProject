#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 3e4;

vector<int> st[4 * MAXN + 5], a, val;
int n, q;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = {a[l]};
    return;
  }

  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);

  st[id].resize(st[id * 2].size() + st[id * 2 + 1].size());
  merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(),
        st[id * 2 + 1].end(), st[id].begin());
}

int query(int l, int r, int u, int v, int k, int id) {
  if (l > r || l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id].size() -
           (upper_bound(st[id].begin(), st[id].end(), k) - st[id].begin());
  }
  int m = (l + r) / 2;
  return (query(l, m, u, v, k, id * 2) + query(m + 1, r, u, v, k, id * 2 + 1));
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  cin >> q;
  int l, r, k;
  while (q--) {
    cin >> l >> r >> k;
    cout << query(1, n, l, r, k, 1) << "\n";
  }
}
