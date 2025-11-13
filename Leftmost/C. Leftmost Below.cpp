#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int check = 0;
  for (int i = 1; i < n - 1; i++) {
    check = (a[i - 1] > a[i] && a[i + 1] > a[i]);
  }
  if (check) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
