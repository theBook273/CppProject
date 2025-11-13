#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> st, a, guest;
int n, m;

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

void update(int l, int r, int pos, int x, int id) {
  if (l == r) {
    st[id] -= x;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m) {
    update(l, m, pos, x, id * 2);
  } else {
    update(m + 1, r, pos, x, id * 2 + 1);
  }
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int query(int l, int r, int x, int id) {
  if (st[id] < x) {
    return 0;
  }
  if (l == r) {
    return l;
  }
  int m = (l + r) / 2;
  if (st[id * 2] >= x) {
    return query(l, m, x, id * 2);
  } else {
    return query(m + 1, r, x, id * 2 + 1);
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  st.resize((n + 1) * 4 + 5);
  a.resize(n + 1);
  guest.resize(m);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);

  for (auto &i : guest) {
    cin >> i;
  }

  for (int i = 0; i < m; i++) {
    int room = query(1, n, guest[i], 1);
    if (room != 0) {
      update(1, n, room, guest[i], 1);
    }
    guest[i] = room;
  }

  for (auto i : guest) {
    cout << i << " ";
  }
}
