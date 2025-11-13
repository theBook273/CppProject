#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> st, a;
int n, k;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);
  st[id] = __gcd(st[id * 2], st[id * 2 + 1]);
}

int query(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int m = (l + r) / 2;
  int left = query(l, m, u, v, id * 2);
  int right = query(m + 1, r, u, v, id * 2 + 1);
  return __gcd(left, right);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> k;
  a.resize(n + 1);
  st.resize(n * 4 + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);
  int res = LLONG_MIN;
  for (int i = 1; i <= n - k + 1; i++) {
    res = max(res, query(1, n, i, i + k - 1, 1));
  }
  cout << res;
}
