#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  double n;
  cin >> n;
  int res = (pow(n, 2.0) / 4 + 1);
  cout << res << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
