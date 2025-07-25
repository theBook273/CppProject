#include <bits/stdc++.h>

using namespace std;

long long a[100000], st[1000000];

void build(long long l, long long r, long long id) {
  if (l == r) {
    st[id] = a[l];
    return;
  }

  long long m = (l + r) / 2;

  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);

  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

long long fMax(long long id, long long l, long long r, long long u,
               long long v) {
  if (l > v || u > r) {
    return -1e9;
  }

  if (u <= l && r <= v) {
    return st[id];
  }

  long long m = (l + r) / 2;

  long long left = fMax(id * 2, l, m, u, v);
  long long right = fMax(id * 2 + 1, m + 1, r, u, v);

  return max(left, right);
}

void replaceST(long long id, long long l, long long r, long long i,
               long long v) {
  if (i < l || r < i) {
    return;
  }

  if (l == r) {
    st[id] = v;
    return;
  }

  long long m = (l + r) / 2;
  replaceST(id * 2, l, m, i, v);
  replaceST(id * 2 + 1, m + 1, r, i, v);

  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  long long n;

  cin >> n;

  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);

  long long q;

  cin >> q;

  while (q--) {
    long long check, a, b;

    cin >> check >> a >> b;

    if (check == 1) {
      replaceST(1, 1, n, a, b);
    }

    else {
      cout << fMax(1, 1, n, a, b) << endl;
    }
  }
}
