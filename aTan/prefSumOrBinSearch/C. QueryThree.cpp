#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vector<int> pref(n);
  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = a[i] + pref[i - 1];
  }

  int l, r, m, res;
  for (int i = 0; i < n; i++) {
    l = 0, r = i, res = -1;
    while (l <= r) {
      m = (l + r) / 2;
      int tongDay = pref[i] - (m ? pref[m - 1] : 0);
      if (tongDay <= k) {
        res = m + 1;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << res << "\n";
  }
}
