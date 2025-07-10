#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    int res = 1e9;
    for (int i = 0; i < n; i++) {
      int maxn = a[i];
      for (int j = i + 1; j < n; j++) {
        maxn = max(maxn, a[j]);
        res = min(res, maxn);
      }
    }
    cout << res - 1 << "\n";
  }
}
