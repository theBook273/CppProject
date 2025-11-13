#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int dis = (b - a);
  if (dis <= -1) {
    if (a % 2 != 0 && dis == -1) {
      cout << y;
    } else {
      cout << -1;
    }
  } else {
    int res = 0;
    for (int i = 1; i <= dis; i++) {
      if (a % 2 == 0) {
        res += min(x, y);
      } else {
        res += x;
      }
      a++;
    }
    cout << res;
  }
  cout << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
