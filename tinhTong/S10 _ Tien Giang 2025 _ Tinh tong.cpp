#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
  // freopen("sum.inp", "r", stdin);
  // freopen("sum.out", "w", stdout);
  int n;
  cin >> n;
  int temp = n / 2;
  if (n & 1) {
    temp++;
  }
  cout << temp * (((n & 1) ? 1 : 2) + n) / 2;
}
