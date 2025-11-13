#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  if (s.size() >= 3) {
    unordered_set<char> cn;
    string res;
    for (int i = 0; i < s.size(); i++) {
      cn.clear();
      res.clear();
      for (int j = 0; j < 3; j++) {
        if (j + i >= s.size()) {
          break;
        }
        cn.insert(s[i + j]);
        res.push_back(s[i + j]);
        if (j == 1) {
          if (cn.size() == 1) {
            cout << res << "\n";
            return;
          }
        }
      }
      if (cn.size() >= 3) {
        cout << res << "\n";
        return;
      }
    }
  } else if (s.size() == 2 && s[0] == s[1]) {
    cout << s << "\n";
    return;
  }
  cout << -1 << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
