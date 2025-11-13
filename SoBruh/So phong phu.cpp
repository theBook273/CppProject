#include <bits/stdc++.h>
#define int long long

using namespace std;

bool check(int n) {
  int tong = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      tong += i;
      if (n / i != i && n / i != n) {
        tong += (n / i);
      }
    }
    if (tong > n)
      return 1;
  }
  return n < tong;
}

signed main() {
  int n;
  cin >> n;
  cout << check(n);
}
