#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;

int n, q, timer = 0;
vector<int> tin, tout, pos, a, lazy, st, adj[N + 5];

void dfsSetUp(int u, int p) {
  tin[u] = ++timer;
  pos[timer] = u;
  for (auto v : adj[u]) {
    if (v != p) {
      dfsSetUp(v, u);
    }
  }
  tout[u] = timer;
}

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = pos[l];
    return;
  }

  int m((l + r) >> 1);
  build(l, m, (id << 1));
  build(m + 1, r, (id << 1) | 1);
  st[id] = st[id << 1] + st[(id << 1) | 1];
}

void applyFlip(int id, int l, int r) {
  st[id] = (r - l + 1) - st[id];
  lazy[id] ^= 1;
}

void push(int id, int l, int r) {
  if (lazy[id]) {
    int mid = (l + r) >> 1;
    applyFlip(id << 1, l, mid);
    applyFlip(id << 1 | 1, mid + 1, r);
    lazy[id] = 0;
  }
}

void update(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return;
  }
  if (u <= l && r <= v) {
    applyFlip(id, l, r);
    return;
  }
  push(id, l, r);
  int m((l + r) >> 1);
  update(l, m, u, v, id << 1);
  update(m + 1, r, u, v, id << 1 | 1);
  st[id] = st[id << 1] + st[id << 1 | 1];
}

int query(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  push(id, l, r);
  int m((l + r) >> 1);
  return query(l, m, u, v, id << 1) + query(m + 1, r, u, v, id << 1 | 1);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  tin.resize(N + 1, 0);
  lazy.resize(4 * N + 1, 0);
  st.resize(4 * N + 1, 0);
  tout.resize(N + 1, 0);
  pos.resize(N + 1, 0);
  a.resize(N + 1, 0);

  cin >> n;
  for (int u, i = 2; i <= n; i++) {
    cin >> u;
    adj[u].push_back(i);
    adj[i].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  dfsSetUp(1, -1);

  for (int i = 1; i <= n; i++) {
    pos[tin[i]] = a[i];
  }

  build(1, n, 1);

  cin >> q;
  string type;
  int u;
  while (q--) {
    cin >> type >> u;
    if (type == "pow") {
      update(1, n, tin[u], tout[u], 1);
    } else {
      cout << query(1, n, tin[u], tout[u], 1) << "\n";
    }
  }
}
