#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j != i) {
        a[i] &= a[j];
      }
    }
    cout << a[i] << "\n";
    return;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
