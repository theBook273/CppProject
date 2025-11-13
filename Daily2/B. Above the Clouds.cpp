#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<char> s(n);
  map<int, int> mp;
  for (auto &i : s) {
    cin >> i;
    mp[i]++;
  }
  for (int i = 1; i < n - 1; i++) {
    if (mp[s[i]] > 1) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
