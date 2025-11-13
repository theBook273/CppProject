#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int res = 1;
  int temp = 0;
  for (int i = n - 1; i >= 0; --i) {
    temp = __gcd(temp, a[i]);
    res = lcm(res, a[i] / temp);
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
