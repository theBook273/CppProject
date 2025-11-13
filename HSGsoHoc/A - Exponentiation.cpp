#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

const int mod = 1e9 + 7;

int binPow(int a, int b) {
  int res = 1;
  while (b != 0) {
    if (b % 2 != 0) {
      res = (res % mod) * (a % mod);
    }
    b /= 2;
    a = (a % mod) * (a % mod);
  }
  res %= mod;
  return res;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << binPow(a, b) << "\n";
  }
}
