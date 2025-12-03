#include <bits/stdc++.h>

using namespace std;

string s;

bool check(int x) {
  string mod = s.substr(0, x);
  for (int i = 0; i < (int)s.size(); i += x) {
    string temp = s.substr(i, x);
    if (temp != mod) {
      return 0;
    }
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;

  if (s.size() > 1) {
    for (int i = 1; i <= (int)(s.size() + 1) / 2; i++) {
      if (check(i)) {
        cout << 1;
        return 0;
      }
    }
  }
  cout << 0;
}
