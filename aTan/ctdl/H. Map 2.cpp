#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> mp;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;

  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    mp[temp].push_back(i + 1);
  }

  int q, que;
  cin >> q;
  while (q--) {
    cin >> que;
    if (mp.count(que)) {
      for (int i : mp[que]) {
        cout << i << " ";
      }
      cout << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
