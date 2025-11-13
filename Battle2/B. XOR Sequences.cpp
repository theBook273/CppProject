#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  int bruh = (a ^ b);
  int res = 1;
  while ((res & bruh) != res) {
    res <<= 1;
  }
  cout << res << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
