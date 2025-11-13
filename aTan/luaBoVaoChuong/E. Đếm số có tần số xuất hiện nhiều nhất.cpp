#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  vector<int> dem(1e6 + 1, 0);
  int n;
  cin >> n;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    dem[temp]++;
  }

  int maxF = 0, cnt = 0;

  for (int i = 1; i <= 1e6; i++) {
    if (maxF < dem[i]) {
      maxF = dem[i];
      cnt = 1;
    } else if (maxF == dem[i]) {
      cnt++;
    }
  }
  cout << maxF << " " << cnt;
}
