#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

signed main() {
  freopen("DAOCHU.INP", "r", stdin);
  freopen("DAOCHU.OUT", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    vector<string> s(2);
    for (auto &i : s) {
      cin >> i;
    }
    reverse(s.begin(), s.end());
    for (auto i : s) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
