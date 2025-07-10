#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
      cin >> i;
    b[0] = -1;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i - 1]) {
        b[i] = i - 1;
      } else if (a[i] == a[i - 1]) {
        b[i] = b[i - 1];
      }
    }
    int x;
    cin >> x;
    while (x--) {
      int l, r;
      cin >> l >> r;
      if (b[r - 1] + 1 >= l) {
        cout << b[r - 1] + 1 << " " << r << "\n";
      } else {
        cout << -1 << " " << -1 << "\n";
      }
    }
    cout << "\n";
  }
}
