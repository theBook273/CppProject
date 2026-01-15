#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;
const int oo = 1e18;

int n, q, timer = 0;
vector<int> st, lazy, tin, tout, pos, adj[N + 5];

void euler(int u, int p) {
  tin[u] = ++timer;
  pos[timer] = u;
  for (auto v : adj[u]) {
    if (v == p) {
      continue;
    }
    euler(v, u);
  }
  tout[u] = timer;
}

void push(int l, int r, int id) {
  if (lazy[id]) {
    st[id] += lazy[id];
    if (l != r) {
      lazy[id << 1] += lazy[id];
      lazy[id << 1 | 1] += lazy[id];
    }
    lazy[id] = 0;
  }
}

void update(int l, int r, int u, int v, int x, int id) {
  push(l, r, id);
  if (l > r || l > v || u > r) {
    return;
  }
  if (u <= l && r <= v) {
    st[id] += x;
    if (l != r) {
      lazy[id << 1] += x;
      lazy[id << 1 | 1] += x;
    }
    return;
  }
  int m((l + r) >> 1);
  update(l, m, u, v, x, id << 1);
  update(m + 1, r, u, v, x, id << 1 | 1);
  st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int get(int l, int r, int u, int v, int id) {
  push(l, r, id);
  if (l > r || l > v || u > r) {
    return -oo;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int m((l + r) >> 1);
  return max(get(l, m, u, v, id << 1), get(m + 1, r, u, v, id << 1 | 1));
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  st.resize(n * 4 + 5, 0);
  lazy.resize(n * 4 + 5, 0);
  tin.resize(n + 1, 0);
  tout.resize(n + 1, 0);
  pos.resize(n + 1, 0);

  for (int u, v, i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  euler(1, -1);

  for (int i = 1; i <= n; ++i) {
    pos[tin[i]] = 0;
  }

  cin >> q;
  int type, x, y;
  while (q--) {
    cin >> type;
    if (type == 2) {
      cin >> x;
      cout << get(1, n, tin[x], tout[x], 1) << "\n";
    } else {
      cin >> x >> y;
      update(1, n, tin[x], tout[x], y, 1);
    }
  }
}
