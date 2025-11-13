#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int res = 1e9;
  if (s.size() > 1) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '0') {
        int dem = s.size() - i - 1;
        for (int j = i - 1; j >= 0; j--) {
          dem += (s[j] != '0');
        }
        res = min(res, dem);
      }
    }
  }
  if (res == 1e9) {
    cout << 0;
  } else {
    cout << res;
  }
  cout << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
