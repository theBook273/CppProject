#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("SODEP.INP", "r", stdin);
  freopen("SODEP.OUT", "w", stdout);

  int n, tong = 0;
  cin >> n;
  while (n) {
    tong += (n % 10);
    n /= 10;
  }

  cout << (tong % 10 == 9);
}
