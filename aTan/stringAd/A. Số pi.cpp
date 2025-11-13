#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  string s = "314159265358979323846264338327 ";

  string temp;
  int t;
  cin >> t;
  while (t--) {
    cin >> temp;
    for (int i = 0; i < s.size(); i++) {
      if (temp[i] != s[i]) {
        cout << i << "\n";
        break;
      }
    }
  }
}
