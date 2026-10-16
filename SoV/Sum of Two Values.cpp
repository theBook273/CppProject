#include <bits/stdc++.h>

using namespace std;

signed main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  map<int, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    mp[a[i]].push_back(i);
  }

  for (int i = 0; i < n; ++i) {
    int hieu = x - a[i];
    if (mp.count(hieu)) {
      for (auto &j : mp[hieu]) {
        if (j != i) {
          cout << j + 1 << " " << i + 1;
          return 0;
        }
      }
    }
  }

  cout << "IMPOSSIBLE";
}
