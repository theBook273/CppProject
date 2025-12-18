#include <bits/stdc++.h>

using namespace std;

int n, q, k;

namespace sub1 {

signed solve() {
  int a[n];

  for (auto &i : a) {
    cin >> i;
  }

  int l, r;
  while (q--) {
    cin >> l >> r;
    sort(a + l, a + r + 1);
  }

  cout << a[k];

  return 0;
}

} // namespace sub1

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q >> k;
  return sub1::solve();
}
