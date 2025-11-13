#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;

  int tong = 0;

  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      tong += (2 % i == 0);
      if (n / i != i) {
        tong += (2 % (n / i) == 0);
      }
    }
  }

  cout << tong << "\n";
}
