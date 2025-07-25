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
    for (auto &i : b)
      cin >> i;
    if (a.back() == b.back()) {
      cout << n << "\n";
      continue;
    }
    int ans = -1;
    vector<int> seen(n + 1);
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] || seen[a[i]] ||
          seen[b[i]]) {
        ans = i;
        break;
      }
      seen[a[i + 1]] = seen[b[i + 1]] = 1;
    }
    cout << ans + 1 << "\n";
  }
}
