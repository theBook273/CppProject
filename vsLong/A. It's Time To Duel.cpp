#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int tong = 0;
  int last = -1;
  bool check = 0;
  for (auto &i : a) {
    cin >> i;
    tong += i;
    if (last == i && last == 0) {
      check = 1;
    }
    last = i;
  }
  if (tong == n || check == 1) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
