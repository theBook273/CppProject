#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << -1 << "\n";
  } else {
    int res = 1;
    while (res < max(a, b)) {
      res <<= 1;
    }
    cout << res - max(a, b) << "\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
