#include <bits/stdc++.h>

using namespace std;

bool aConB(string a, string b) {
  for (int i = 0; i < (int)b.size(); i++) {
    string temp = b.substr(i, a.size());
    if (temp == a) {
      return 1;
    }
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> t >> s;

  if (t.size() > s.size()) {
    cout << 0;
    return 0;
  }

  int dem = 0;
  string now = t;
  while (aConB(now, s)) {
    now += t;
    dem++;
  }

  cout << dem;
}
