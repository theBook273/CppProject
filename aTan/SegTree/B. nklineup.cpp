#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2 * 1e5;
int stMin[MAXN * 4 + 5], stMax[MAXN * 4 + 5], a[MAXN + 5];
int n, q;

void build(int l, int r, int id) {
  if (l == r) {
    stMax[id] = a[l];
    stMin[id] = a[l];
    return;
  }

  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);

  stMax[id] = max(stMax[id * 2], stMax[id * 2 + 1]);
  stMin[id] = min(stMin[id * 2], stMin[id * 2 + 1]);
}

int queryMax(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return -1e6;
  }

  if (u <= l && r <= v) {
    return stMax[id];
  }

  int m = (l + r) / 2;
  int left = queryMax(l, m, u, v, id * 2);
  int right = queryMax(m + 1, r, u, v, id * 2 + 1);

  return max(left, right);
}

int queryMin(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return 1e6;
  }

  if (u <= l && r <= v) {
    return stMin[id];
  }

  int m = (l + r) / 2;
  int left = queryMin(l, m, u, v, id * 2);
  int right = queryMin(m + 1, r, u, v, id * 2 + 1);

  return min(left, right);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  int l, r;
  while (q--) {
    cin >> l >> r;
    cout << queryMax(1, n, l, r, 1) - queryMin(1, n, l, r, 1) << "\n";
  }
}
