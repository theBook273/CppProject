#include <bits/stdc++.h>

using namespace std;

const int maxn = 50000 + 27;

int a[maxn], table[20][maxn];
int n, q, k;

void build() {
  for (int j = 1; j <= n; ++j) {
    table[0][j] = a[j];
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      table[i][j] = max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }
  }
}

int query(int l, int r) {
  int p = log2(r - l + 1);
  return max(table[p][l], table[p][r - (1 << p) + 1]);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;
  k = log2(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build();
  int l, r, tong = 0;
  while (q--) {
    cin >> l >> r;
    if (a[l] >= query(l, r - 1)) {
      tong++;
    }
  }
  cout << tong << "\n";
}
