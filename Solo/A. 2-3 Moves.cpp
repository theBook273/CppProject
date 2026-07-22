#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  int res = 1e9;
  cin >> n;
  if (n % 2 == 0) {
    res = min(n / 2, res);
  }
  if (n % 3 == 0) {
    res = min(n / 3, res);
  }
  cout << n % 3 << " " << n % 2 << " ";
  cout << res << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
