#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  if (k == n) {
    for (int i = 0; i < n; i++) {
      cout << 1 << " ";
    }
  } else if (k == 1) {
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
  } else {
    cout << -1;
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
