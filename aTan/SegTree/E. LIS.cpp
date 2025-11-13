#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a, val, st, dp;
int n;

void update(int l, int r, int pos, int tar, int id) {
  if (l == r) {
    st[id] = tar;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m) {
    update(l, m, pos, tar, id * 2);
  } else {
    update(m + 1, r, pos, tar, id * 2 + 1);
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
  dp.resize(n);
  st.resize(n * 4 + 5);
  for (auto &i : a) {
    cin >> i;
  }

  val = a;
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (int &i : a) {
    i = lower_bound(val.begin(), val.end(), i) - val.begin() + 1;
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    int best = 0;
    if (a[i] > 0) {
      best = query(1, val.size(), 1, a[i] - 1, 1);
    }
    dp[i] = best + 1;
    update(1, val.size(), a[i], dp[i], 1);
    res = max(res, dp[i]);
  }
  cout << res;
}
