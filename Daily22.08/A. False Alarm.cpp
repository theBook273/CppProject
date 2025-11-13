#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int dem1 = 0;
  for (auto &i : a) {
    cin >> i;
    dem1 += i;
  }
  bool start = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      start = 1;
    }
    if (start) {
      m -= 1;
      dem1 -= a[i];
    }
    if (m == 0 && dem1 != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
