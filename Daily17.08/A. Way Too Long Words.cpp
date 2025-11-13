#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() <= 10) {
      cout << s << "\n";
    } else {
      cout << s[0] << s.size() - 2 << s.back() << "\n";
    }
  }
}
