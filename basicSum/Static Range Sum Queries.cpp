#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2 * 1e5 + 27;

int table[20][maxn], a[maxn], n, k, q;

void build() {
  for (int j = 1; j <= n; ++j) {
    table[0][j] = a[j];
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      table[i][j] = table[i - 1][j] + table[i - 1][j + (1 << (i - 1))];
    }
  }
}

int query(int l, int r) {
  int tong = 0;
  for (int i = k; i >= 0; --i) {
    if ((1 << i) <= (r - l + 1)) {
      tong += table[i][l];
      l += (1 << i);
    }
  }
  return tong;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;
  k = log2(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build();
  int x, y;
  // for (int i = 0; i <= k; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << table[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  while (q--) {
    cin >> x >> y;
    cout << query(x, y) << "\n";
  }
}
