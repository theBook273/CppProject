#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int dem = 1;
  string temp;
  while (cin >> temp) {
    temp = temp.substr(0, s.size());
    if (temp == s) {
      cout << dem;
      return 0;
    }
    dem++;
  }
  cout << -1;
}
