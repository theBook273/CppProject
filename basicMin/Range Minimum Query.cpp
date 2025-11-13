#include <bits/stdc++.h>

using namespace std;
int table[20][100027];
int n, k, q;
vector<int> a;

void build() {
  for (int i = 1; i <= n; ++i) {
    table[0][i] = a[i];
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }
  }
}

int query(int l, int r) {
  int p = log2(r - l + 1);
  return min(table[p][l], table[p][r - (1 << p) + 1]);
}

signed main() {
  cin >> n;
  k = log2(n);
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build();
  cin >> q;
  int l, r;
  while (q--) {
    cin >> l >> r;
    l++, r++;
    cout << query(l, r) << "\n";
  }
}
