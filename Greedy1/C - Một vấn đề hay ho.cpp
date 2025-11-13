#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n & 1) {
      cout << l << "\n";
    } else {

      if (n == 2) {
        cout << -1 << "\n";
      } else {
        int res = 1;
        bool check = 0;
        while (res <= r) {

          if (res > l) {
            check = 1;
            if (k <= n - 2) {
              cout << l << "\n";
            } else {
              cout << res << "\n";
            }
            break;
          }

          res *= 2;
        }

        if (!check) {
          cout << -1 << "\n";
        }
      }
    }
  }
}
