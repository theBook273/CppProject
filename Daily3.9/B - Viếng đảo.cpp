#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k < n - 1) {
      cout << n << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
}
