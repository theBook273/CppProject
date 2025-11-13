#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> mp(10, 0);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (auto i : s) {
      mp[i - '0']++;
    }
  }
  for (int i = 0; i <= 9; i++) {
    cout << mp[i] << " ";
  }
}
