#include <bits/stdc++.h>

using namespace std;

void solve() {
  int l, r, x, y;
  cin >> l >> r >> x >> y;
  int inside = min(r, y) - max(l, x) + 1;
  int ans = inside - 1;
  if (inside <= 0) {
    ans = 1;
  } else {
    ans += (l != x);
    ans += (r != y);
  }
  cout << ans << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
