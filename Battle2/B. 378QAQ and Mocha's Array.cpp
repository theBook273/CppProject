#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % a[0] != 0) {
      id = i;
      break;
    }
  }
  for (int i = n - 1; i > 1; i--) {
    if (a[i] % a[0] != 0 && a[i] % a[id] != 0) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
