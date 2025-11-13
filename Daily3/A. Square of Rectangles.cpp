#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int l1, l2, l3, b1, b2, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if ((l1 == l2 && l2 == l3) && (l1 == (b1 + b2 + b3)) ||
        ((b1 == b2 && b2 == b3) && (b1 == (l1 + l2 + l3)))) {
      cout << "YES\n";
    } else if ((b2 + b3 == b1 && b1 == l1 + l2 && l2 == l3) ||
               (l2 + l3 == l1 && l1 == b1 + b2 && b2 == b3)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
