#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> st, a;
int n;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int mid((l + r) / 2);
  build(l, mid, id << 1);
  build(mid + 1, r, id << 1 | 1);
  st[id] = min(st[id << 1], st[id << 1 | 1]);
}

int query(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return LLONG_MAX;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int mid((l + r) / 2);
  return min(query(l, mid, u, v, id << 1),
             query(mid + 1, r, u, v, id << 1 | 1));
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test", "r", stdin);
  freopen("testTrau", "w", stdout);

  cin >> n;
  a.resize(n + 1);
  st.resize(4 * n + 5, LLONG_MIN);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  for (int x = 1; x <= n; x++) {
    int res = LLONG_MIN;
    for (int i = 1; i + x - 1 <= n; i++) {
      res = max(query(1, n, i, i + x - 1, 1), res);
    }
    cout << res << " ";
  }
}
