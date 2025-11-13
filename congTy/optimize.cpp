#include <bits/stdc++.h>

using namespace std;

struct node {
  int best;
  int maxPre;
  int maxSuf;
  int maxVal;
  int minVal;
  int lazy;
};

node st[100000];
vector<int> a;

void mergeNode(node left, node right, node &tar) {
  tar.minVal = min(left.minVal, right.minVal);
  tar.maxVal = max(left.maxVal, right.maxVal);

  tar.best =
      max({left.best, right.best, left.maxSuf + right.maxVal - right.minVal});

  tar.maxPre = max(left.maxPre, right.maxPre + (left.maxVal - left.minVal));
  tar.maxSuf = max(right.maxSuf, left.maxSuf + (right.maxVal - right.minVal));
}

void build(int l, int r, int id) {
  if (l == r) {
    st[id].best = 0;
    st[id].maxPre = st[id].maxSuf = st[id].maxVal = st[id].minVal = a[l];
    st[id].lazy = 0;
    return;
  }

  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);
  mergeNode(st[id * 2], st[id * 2 + 1], st[id]);
}

void increase(node &temp, int x) {
  temp.minVal += x;
  temp.maxVal += x;
  temp.lazy += x;
}

void pushDown(node &cur, node &left, node &right) {
  if (cur.lazy != 0) {
    increase(left, cur.lazy);
    increase(right, cur.lazy);
    cur.lazy = 0;
  }
}

void update(int l, int r, int u, int v, int x, int id) {
  if (l > v || u > r) {
    return;
  }
  if (u <= l && r <= v) {
    increase(st[id], x);
    return;
  }
  pushDown(st[id], st[id * 2], st[id * 2 + 1]);

  int m = (l + r) / 2;
  update(l, m, u, v, x, id * 2);
  update(m + 1, r, u, v, x, id * 2 + 1);
}

signed main() {
  // freopen("GROUP.INP", "r", stdin);
  // freopen("GROUP.OUT", "w", stdout);
  int n, q;
  cin >> n >> q;

  a.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  while (q--) {
    int que;
    cin >> que;
    if (que == 2) {
      cout << st[1].best << "\n";
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      update(1, n, l, r, x, 1);
    }
  }
}
