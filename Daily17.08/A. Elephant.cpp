#include <bits/stdc++.h>

using namespace std;

int step[] = {5, 4, 3, 2, 1};

signed main() {
  int n;
  cin >> n;

  int dem = 0, tong = 0;

  for (int i = 0; i < 5; i++) {
    if (n >= step[i]) {
      int toWalk = (n / step[i]);
      n -= toWalk * step[i];
      tong += toWalk;
    }
  }
  cout << tong << "\n";
}
