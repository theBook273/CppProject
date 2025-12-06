#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a, st;
vector<pair<int, int>> learn;
int n;
bool flag = 0;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

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

  freopen("INCOME.INP", "r", stdin);
  freopen("INCOME.OUT", "w", stdout);

  cin >> n;
  st.resize(n * 4 + 5);
  a.resize(n + 1);
  learn.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    cin >> learn[i].first >> learn[i].second;
  }

  for (int q = 1; q <= n; q++) {
    flag = 0;
    for (int i = 1; i <= n; i++) {
      int temp = query(1, n, learn[i].first, learn[i].second, 1);
      if (temp > a[i]) {
        a[i] = temp;
        update(1, n, i, a[i], 1);
        flag = 1;
      }
    }
    if (!flag) {
      cout << q;
      break;
    }
  }
}
