#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int ans = 1, cur = 1;; ans++, cur = cur * 2 + 2) {
    if (cur >= n) {
      cout << ans << "\n";
      return;
    }
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
