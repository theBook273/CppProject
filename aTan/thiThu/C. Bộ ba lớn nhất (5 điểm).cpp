#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  unordered_map<int, int> mp;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    for (int j = 1; j * j <= temp; j++) {
      if (temp % j == 0) {
        mp[j]++;
        if (temp / j != j) {
          mp[temp / j]++;
        }
      }
    }
  }

  int res = 1;
  for (auto [i, j] : mp) {
    if (j >= 3) {
      res = max(res, i);
    }
  }
  cout << res;
}
