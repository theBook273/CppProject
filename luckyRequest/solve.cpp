#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 27;

struct node {
  int n4, n7, n47, n74;
  node() {
    n4 = n7 = 0;
    n47 = n74 = 1;
  }
};

int lazy[maxn * 4];
node st[maxn * 4];
string a;

void merge(node &left, node &right, node &now) {
  now.n4 = left.n4 + right.n4;
  now.n7 = left.n7 + right.n7;
  now.n47 = max({left.n47 + right.n7, left.n4 + right.n47, left.n4 + right.n7});
  now.n74 = max({left.n74 + right.n4, left.n7 + right.n74, left.n7 + right.n4});
}

void switching(node &now) {
  swap(now.n4, now.n7);
  swap(now.n47, now.n74);
}

void push(int id, int l, int r) {
  if (lazy[id] != 0) {
    if (lazy[id] % 2 != 0) {
      switching(st[id]);
    }
    if (l != r) {
      lazy[id * 2] += lazy[id];
      lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
  }
}

void build(int id, int l, int r) {
  if (l == r) {
    st[id] = node();
    int temp = a[l] - '0';
    if (temp == 4) {
      st[id].n4++;
    } else {
      st[id].n7++;
    }
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  merge(st[id * 2], st[id * 2 + 1], st[id]);
}

void update(int id, int l, int r, int u, int v) {
  push(id, l, r);
  if (l > r || l > v || u > r) {
    return;
  }
  if (u <= l && r <= v) {
    switching(st[id]);
    if (l != r) {
      lazy[id * 2]++;
      lazy[id * 2 + 1]++;
    }
    return;
  }
  int m = (l + r) / 2;
  update(id * 2, l, m, u, v);
  update(id * 2 + 1, m + 1, r, u, v);
  merge(st[id * 2], st[id * 2 + 1], st[id]);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q >> a;
  build(1, 0, n - 1);
  string que;
  int x, y;
  while (q--) {
    cin >> que;
    if (que == "count") {
      cout << st[1].n47 << "\n";
    } else {
      cin >> x >> y;
      x--;
      y--;
      update(1, 0, n - 1, x, y);
    }
  }
}
