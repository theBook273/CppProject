#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  unordered_map<int, int> dem;

  int n;
  cin >> n;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    dem[temp - i + 1]++;
  }

  int res = 0;

  for (auto [i, j] : dem) {
    if (j != 0) {
      res += (j * (j - 1)) / 2;
    }
  }

  cout << res;
}
