#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  string s;
  set<string> res;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i]) && s[i] != '0') {
      int r = i;
      string temp;
      while (isdigit(s[r]) && r < s.size()) {
        temp.push_back(s[r]);
        r++;
      }
      i = r;
      res.insert(temp);
    }
  }
  cout << res.size();
}
