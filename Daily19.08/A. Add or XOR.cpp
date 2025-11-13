#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int dis = b - a;
  if (dis < 0) {
    if (dis == -1 && a % 2 != 0) {
      cout << y << "\n";
    } else {
      cout << -1 << "\n";
    }
  } else {
    int res = 0;
    for (int i = a; i < b; i++) {
      if (i % 2 == 0) {
        res += min(x, y);
      } else {
        res += x;
      }
    }
    cout << res << "\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
