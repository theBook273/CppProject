#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  vector<int> dem(26, 0);
  string s;
  cin >> s;
  for (auto i : s) {
    dem[i - 'a']++;
  }
  for (auto i : dem) {
    cout << i << " ";
  }
}
