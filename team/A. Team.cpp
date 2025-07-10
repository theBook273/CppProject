#include <bits/stdc++.h>

signed main() {
  int n;
  std::cin >> n;
  int tong = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + b + c >= 2) {
      tong++;
    }
  }
  std::cout << tong << "\n";
}
