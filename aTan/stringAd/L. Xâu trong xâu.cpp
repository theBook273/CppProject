#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;

  for (int i = 0; i < (int)b.size(); i++) {
    string temp = b.substr(i, a.size());
    if (temp == a) {
      cout << i;
      return 0;
    }
  }

  cout << -1;
}
