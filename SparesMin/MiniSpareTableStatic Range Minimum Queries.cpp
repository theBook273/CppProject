#include <bits/stdc++.h>

using namespace std;

const int maxn = 2 * 1e5 + 27;

int table[20][maxn], a[maxn], n, k, q;

signed main() {
  cin.tie()->sync_with_stdio(0);

  cin >> n >> q;
  k = log2(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int j = 1; j <= n; ++j) {
    table[0][j] = a[j];
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }
  }

  // for (int i = 0; i <= k; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << table[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  int x, y, p;
  while (q--) {
    cin >> x >> y;
    p = log2(y - x + 1);
    cout << min(table[p][x], table[p][y - (1 << p) + 1]) << "\n";
  }
}
