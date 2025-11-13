#include <bits/stdc++.h>

using namespace std;

int a[] = {1, 5, 10, 20, 100};

signed main() {
  int n;
  cin >> n;

  int tong = 0;

  for (int i = 4; i >= 0; i--) {
    tong += (n / a[i]);
    n -= (n / a[i]) * a[i];
  }

  cout << tong << "\n";
}
