#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int best = 1;
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
        best = n / i;
        break;
      }
    }
    cout << best << " " << n - best << "\n";
  }
}
