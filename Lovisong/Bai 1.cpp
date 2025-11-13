#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  int n;
  int dem = 30, tong = 0;
  cin >> n;
  while (n >= 5) {
    n -= 5;
    tong += dem * 5;
    dem += 30;
  }
  tong += dem * n;
  cout << tong;
}
