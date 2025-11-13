#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  vector<int> dem(1e5 + 1, 0);

  int n;
  cin >> n;

  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    dem[temp]++;
    if (dem[temp] == 2) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}
