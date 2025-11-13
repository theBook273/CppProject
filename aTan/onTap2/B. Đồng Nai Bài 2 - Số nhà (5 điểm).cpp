#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;

  int k = 9, dem = 1, tong = 0;
  while (n - k >= 0 && k <= 1000000000) {
    n -= k;
    tong += k * dem;
    k = k * 10 + 9;
    dem++;
  }
  tong += dem * n;
  cout << tong * 80000;
}
