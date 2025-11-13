#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> mp(1e6 + 273, 0);
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    mp[temp]++;
  }
  int q, ask;
  cin >> q;
  while (q--) {
    cin >> ask;
    cout << mp[ask] << "\n";
  }
}
