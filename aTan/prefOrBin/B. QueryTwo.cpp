#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  sort(a.begin(), a.end());
  int q, x, res = -1;
  cin >> q;
  while (q--) {
    cin >> x;
    res = -1;
    int l = 0, r = n - 1, m;
    while (l <= r) {
      m = (l + r) / 2;
      if (a[m] <= x) {
        res = a[m];
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    cout << res << "\n";
  }
}
