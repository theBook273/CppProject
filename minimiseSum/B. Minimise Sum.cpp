#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int tong = 0;
    for (int &i : a) {
      cin >> i;
      tong += i;
    }
    if (n <= 2) {
      cout << tong << "\n";
      continue;
    }
    cout << (min(a[0], a[1]) + a[0]) << "\n";
  }
}
