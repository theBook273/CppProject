#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, k;
    cin >> a >> b >> k;
    if (k <= (min(a, b))) {
      cout << 0 << " " << 0 << " " << a << " " << 0 << "\n";
      cout << 0 << " " << 0 << " " << 0 << " " << b << "\n";
    } else {
      a = min(a, b);
      cout << 0 << " " << 0 << " " << a << " " << a << "\n";
      cout << a << " " << 0 << " " << 0 << " " << a << "\n";
    }
  }
}
