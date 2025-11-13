#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
    if (mp[a[i]] > 1) {
      cout << "YES\n";
      return;
    }
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
