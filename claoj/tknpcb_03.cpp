#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, tong = 0;
  cin >> n;
  for (int a, i = 0; i < n; i++) {
    cin >> a;
    tong += a;
  }
  cout << tong;
}
