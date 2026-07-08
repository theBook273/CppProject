#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  getline(cin, s);
  map<char, int> mp;

  for (auto &i : s) {
    char temp = tolower(i);
    if (temp != ' ') {
      mp[temp]++;
    }
  }

  for (auto &[i, j] : mp) {
    cout << i << " " << j << "\n";
  }
}
