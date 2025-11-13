#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int a[n + 1][m + 1];
  int r[n + 1], c[m + 1];
  int maxn = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      maxn = max(maxn, a[i][j]);
      r[i] = 0;
      c[j] = 0;
    }
  }

  int tong = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      tong += (maxn == a[i][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == maxn) {
        r[i]++;
        c[j]++;
      }
    }
  }

  bool flag = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (r[i] + c[j] - (a[i][j] == maxn) == tong) {
        flag = 1;
        break;
      }
    }
  }

  cout << maxn - flag << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
