#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

const int mod = 1e9 + 7;

int pw(int a, int b) {
  int res = 1;
  while (b != 0) {
    if (b & 1) {
      res = res * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}

int sumlr(int l, int r) {
  l %= mod;
  r %= mod;
  return (r * (r + 1) % mod * pw(2, mod - 2) % mod -
          l * (l - 1 + mod) % mod * pw(2, mod - 2) % mod + mod) %
         mod;
}

int sumD(int a) {
  int res = 0;
  int l = 1;
  while (l <= a) {
    int k = a / l;
    int r = a / k;
    res = (res + k * sumlr(l, r)) % mod;
    l = r + 1;
  }
  return res;
}

signed main() {
  int n;
  cin >> n;
  cout << sumD(n);
}
