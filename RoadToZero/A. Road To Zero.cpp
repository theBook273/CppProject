#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int a, b, x, y;
  cin >> x >> y >> a >> b;
  int c1 = abs(x - y) * a + b * min(x, y);
  int c2 = a * (x + y);
  cout << min(c1, c2) << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
