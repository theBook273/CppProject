#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int maxw = 0, maxh = 0;
  int a[100 + 1][100 + 1];

  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      a[i][j] = 0;
    }
  }

  while (n--) {
    int w, h;
    cin >> w >> h;
    maxw = max(maxw, w);
    maxh = max(maxh, h);
    for (int i = 1; i <= w; i++) {
      for (int j = 1; j <= h; j++) {
        a[i][j] = 1;
      }
    }
  }

  int tong = (maxw + maxh) * 2;

  // for (int i = 1; i <= 10; i++) {
  //   for (int j = 1; j <= 10; j++) {
  //     cout << a[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  //
  // for (int i = 1; i <= maxw; i++) {
  //   tong += a[i][1];
  // }
  //
  // for (int j = 1; j <= maxh; j++) {
  //   tong += a[1][j];
  // }

  cout << tong << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
