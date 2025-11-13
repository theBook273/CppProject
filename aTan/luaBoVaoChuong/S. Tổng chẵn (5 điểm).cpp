#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  vector<int> dem(2, 0);

  int n, tong = 0;
  cin >> n;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    tong += temp;
    dem[temp % 2]++;
  }

  if (tong % 2 == 0) {
    cout << (dem[0] * (dem[0] - 1)) / 2 + (dem[1] * (dem[1] - 1)) / 2;
  } else {
    cout << dem[0] * dem[1];
  }
}
