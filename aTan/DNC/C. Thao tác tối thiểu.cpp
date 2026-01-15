#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;
const int oo = 1e18;

int n;
vector<int> a;
vector<pair<int, int>> st;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = {a[l], l};
    return;
  }
  int m((l + r) >> 1);
  build(l, m, id << 1);
  build(m + 1, r, id << 1 | 1);
  st[id] = min(st[id << 1], st[id << 1 | 1]);
}

pair<int, int> query(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return {oo, oo};
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int m((l + r) >> 1);
  return min(query(l, m, u, v, id << 1), query(m + 1, r, u, v, id << 1 | 1));
}

int dnc(int l, int r, int sub) {
  if (l > r) {
    return 0;
  }

  auto [val, pos] = query(1, n, l, r, 1);
  return min(dnc(l, pos - 1, val) + dnc(pos + 1, r, val) + (val - sub),
             r - l + 1);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  a.resize(n + 1, 0);
  st.resize(n * 4 + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  cout << dnc(1, n, 0);
}
