#include <bits/stdc++.h>

using namespace std;

signed main() {
  int l = 1, r = 100;

  while (l <= r) {
    int m = (l + r) / 2;
    cout << m << "\n";
    bool beHon;
    cin >> beHon;
    if (beHon) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
}
