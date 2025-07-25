#include <bits/stdc++.h>
#define int long long

using namespace std;

int st[9999999];
vector<int> a;

void build(int id, int l, int r, int sta) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m, sta - 1);
  build(id * 2 + 1, m + 1, r, sta - 1);
  st[id] = ((sta % 2 == 0) ? (st[id * 2] | st[id * 2 + 1])
                           : (st[id * 2] ^ st[id * 2 + 1]));
}

void update(int id, int l, int r, int sta, int tar, int data) {
  if (tar < l || r < tar) {
    return;
  }
  if (l == r) {
    st[id] = data;
    return;
  }
  int m = (l + r) / 2;
  if (tar <= m)
    update(id * 2, l, m, sta - 1, tar, data);
  else
    update(id * 2 + 1, m + 1, r, sta - 1, tar, data);
  st[id] = ((sta % 2 == 0) ? (st[id * 2] | st[id * 2 + 1])
                           : (st[id * 2] ^ st[id * 2 + 1]));
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int sta(n + 1);
  n = 1LL << n;
  a.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n, sta);
  int tar, data;
  while (k--) {
    cin >> tar >> data;
    update(1, 1, n, sta, tar, data);
    cout << st[1] << "\n";
  }
}
