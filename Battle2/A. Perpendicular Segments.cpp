#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x, y, k;
  cin >> x >> y >> k;
  if (k <= min(x, y)) {
    cout << 0 << " " << 0 << " " << x << " " << 0 << "\n";
    cout << 0 << " " << 0 << " " << 0 << " " << y << "\n";
  } else {
    int temp = min(x, y);
    cout << 0 << " " << 0 << " " << temp << " " << temp << "\n";
    cout << 0 << " " << temp << " " << temp << " " << 0 << "\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
