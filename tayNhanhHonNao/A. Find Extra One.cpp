#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  map<int, int> mp;
  for (int x, y, i = 0; i < n; i++) {
    cin >> x >> y;
    if (x < 0) {
      mp[-1]++;
    } else {
      mp[1]++;
    }
  }

  if (min(mp[1], mp[-1]) <= 1) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
