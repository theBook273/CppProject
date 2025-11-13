#include <bits/stdc++.h>

using namespace std;

int n, m, h, w, k, half, ans;
vector<vector<int>> a;
vector<int> val, dem, st;

void update(int l, int r, int pos, int x, int id) {
  if (l == r) {
    st[id] += x;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) {
    update(l, mid, pos, x, id * 2);
  } else {
    update(mid + 1, r, pos, x, id * 2 + 1);
  }
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("Anhdep.inp", "r", stdin);
  freopen("Anhdep.out", "w", stdout);

  cin >> n >> m >> h >> w;
  a.resize(n, vector<int>(m));
  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
    }
  }

  for (auto &i : a) {
    for (auto &j : i) {
      val.push_back(j);
    }
  }

  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (auto &i : a) {
    for (auto &j : i) {
      j = lower_bound(val.begin(), val.end(), j) - val.begin() + 1;
    }
  }

  k = val.size();
  st.assign(k * 4 + 1, 0);
  half = (h * w) / 2;
  ans = 0;

  for (int top = 0; top + h <= n; top++) {
    fill(st.begin(), st.end(), 0);

    for (int i = top; i < top + h; i++) {
      for (int j = 0; j < w; j++) {
        update(1, k, a[i][j], 1, 1);
      }
    }

    if (st[1] <= half) {
      ans++;
    }

    for (int left = 1; left + w <= m; left++) {
      for (int i = top; i < top + h; i++) {
        update(1, k, a[i][left - 1], -1, 1);
        update(1, k, a[i][left + w - 1], 1, 1);
      }
      if (st[1] <= half) {
        ans++;
      }
    }
  }

  cout << ans;
}
