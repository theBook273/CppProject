#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Query {
  int loai, x, y;
};

vector<int> a;
vector<Query> query;
int n, q;

namespace sub4 {

vector<int> st;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }

  int mid((l + r) / 2);
  build(l, mid, id << 1);
  build(mid + 1, r, id << 1 | 1);
  st[id] = st[id << 1] + st[id << 1 | 1];
}

void update(int l, int r, int pos, int x, int id) {
  if (l == r) {
    st[id] = x;
    return;
  }
  int mid((l + r) / 2);
  if (pos <= mid) {
    update(l, mid, pos, x, id << 1);
  } else {
    update(mid + 1, r, pos, x, id << 1 | 1);
  }
  st[id] = st[id << 1] + st[id << 1 | 1];
}

int getSum(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int mid((l + r) / 2);
  return getSum(l, mid, u, v, id << 1) + getSum(mid + 1, r, u, v, id << 1 | 1);
}

void solve() {
  st.resize(4 * n + 5, 0);

  build(1, n, 1);

  for (auto &[type, l, r] : query) {
    if (type == 1) {
      for (int i = 1; i <= n; i++) {
        int x = i - 1;
        int y = (x ^ l) % n;
        if (x < y) {
          x++;
          y++;
          swap(a[x], a[y]);
          update(1, n, x, a[x], 1);
          update(1, n, y, a[y], 1);
        }
      }

    }

    else if (type == 2) {
      cout << getSum(1, n, l, r, 1) << "\n";
    }

    else {
      int tong(0);
      for (int i = l, dem = 1; i <= r; i++, dem++) {
        tong += (a[i] * dem);
      }
      cout << tong << "\n";
    }
  }
}

} // namespace sub4

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("XOREX.INP", "r", stdin);
  freopen("XOREX.OUT", "w", stdout);

  cin >> n >> q;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int q1, q2, q3;
  q1 = q2 = q3 = 0;
  query.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> query[i].loai;
    if (query[i].loai == 1) {
      q1++;
      cin >> query[i].x;
    }

    if (query[i].loai == 2) {
      q2++;
      cin >> query[i].x;
      cin >> query[i].y;
      query[i].x++;
      query[i].y++;
    }

    if (query[i].loai == 3) {
      q3++;
      cin >> query[i].x;
      cin >> query[i].y;
      query[i].x++;
      query[i].y++;
    }
  }

  sub4::solve();
}
