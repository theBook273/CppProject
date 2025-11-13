#include <bits/stdc++.h>

using namespace std;

vector<int> st, a, dpT, dpN, val;
int n, M, res;

void update(int l, int r, int tar, int x, int id) {
  if (l == r) {
    st[id] = x;
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
    return 0;
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
  int n;
  cin >> n;
  a.resize(n);
  dpT.resize(n);
  dpN.resize(n);
  st.resize(n * 4 + 1);
  for (auto &i : a) {
    cin >> i;
  }

  val = a;
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  M = val.size();
  for (int &i : a) {
    i = lower_bound(val.begin(), val.end(), i) - val.begin() + 1;
  }

  for (int i = 0; i < n; i++) {
    int best = 0;
    if (a[i] > 0) {
      best = query(1, M, 1, a[i] - 1, 1);
    }
    dpT[i] = best + 1;
    update(1, M, a[i], dpT[i], 1);
  }

  st.assign(n * 4 + 5, 0);
  for (int i = n - 1; i >= 0; i--) {
    int best = 0;
    if (a[i] > 0) {
      best = query(1, M, 1, a[i] - 1, 1);
    }
    dpN[i] = best + 1;
    update(1, M, a[i], dpN[i], 1);
  }

  res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, 2 * min(dpT[i], dpN[i]) - 1);
  }
  cout << res;
}
