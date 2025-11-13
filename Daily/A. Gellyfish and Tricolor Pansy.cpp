#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  // cout << b - a << " " << d - c << "\n";
  if (min(a, c) < min(b, d)) {
    cout << "Flower\n";
  } else {
    cout << "Gellyfish\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
