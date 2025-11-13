#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int res = 1e9, dem = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] + a[n - 1]) % 2 != 0) {
      dem++;
    } else {
      res = min(dem, res);
      dem = 0;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if ((a[i] + a[0]) % 2 != 0) {
      dem++;
    } else {
      res = min(dem, res);
      break;
    }
  }
  cout << res << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
