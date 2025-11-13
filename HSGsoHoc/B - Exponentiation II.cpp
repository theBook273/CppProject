#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int binPow(int a, int b, int mod) {
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
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << binPow(a, binPow(b, c, mod - 1), mod) << "\n";
  }
}
