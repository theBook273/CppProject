#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  unordered_map<char, int> mp;

  int l = 0, r = 0, res = 1e9;
  for (; r < s.size(); r++) {
    mp[s[r]]++;
    if (mp.size() == 3) {
      res = min(res, r - l + 1);
      while (r - l + 1 > 3) {
        mp[s[l]]--;
        if (mp[s[l]] == 0) {
          mp.erase(s[l]);
        }
        l++;
        if (mp.size() == 3) {
          res = min(res, r - l + 1);
        }
      }
    }
  }

  cout << ((res != 1e9) ? res : 0) << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
