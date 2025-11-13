#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> st, a, val;
int n;

void update(int l, int r, int tar, int id) {
  if (l == r) {
    st[id]++;
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
  return left + right;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  a.resize(n + 1);
  st.resize(n * 4 + 5);
  for (auto &i : a) {
    cin >> i;
  }

  // for (auto i : a) {
  //   cout << i << " ";
  // }
  // cout << "\n";

  val = a;
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (int &i : a) {
    i = lower_bound(val.begin(), val.end(), i) - val.begin() + 1;
  }

  int inv = 0;
  for (int i = 0; i < n; i++) {
    inv += query(1, val.size(), a[i] + 1, val.size(), 1);
    update(1, val.size(), a[i], 1);
  }

  cout << inv;
}
