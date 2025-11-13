#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  unordered_set<int> se;
  for (auto i : a) {
    se.insert(i);
  }
  int res = 0;
  for (auto k : se) {
    int tong = 0;
    for (auto i : se) {
      tong += (k ^ i);
    }
    res = max(res, tong);
  }
  cout << res << "\n";
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
