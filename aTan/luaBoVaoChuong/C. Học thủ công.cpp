#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  vector<int> dem(2001, 0);
  int tamGiac = 0, thua = 0;

  int n;
  cin >> n;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    dem[temp]++;
  }

  for (int i = 1; i <= 2001; i++) {
    if (dem[i] > 0) {
      tamGiac += (dem[i] / 3);
      thua += (dem[i] % 3);
    }
  }
  cout << tamGiac << " " << thua;
}
