#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    string suf = "AM";
    cin >> s;
    int hour = (s[0] - '0') * 10 + (s[1] - '0');
    if (hour >= 12) {
      suf = "PM";
      if (hour > 12) {
        hour -= 12;
      }
    }
    if (hour == 0) {
      hour = 12;
    }
    string too = to_string(hour);
    if (too.size() < 2) {
      too = "0" + too;
    }
    cout << too << ":" << s[3] << s[4] << " " << suf << "\n";
  }
}
