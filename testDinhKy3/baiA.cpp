#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    int le = 0, chan = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 != 0 && a[i] % 2 == 0)
        le++;
      if (i % 2 == 0 && a[i] % 2 != 0)
        chan++;
    }
    if (chan == le)
      cout << chan << "\n";
    else
      cout << -1 << "\n";
  }
}
