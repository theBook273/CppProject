#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  long long a, b, c;
  cin >> a >> b >> c;

  a %= b;

  for (int i = 1; i <= 100000; i++) {
    a *= 10;
    int d = a / b;
    if (d == c) {
      cout << i;
      return 0;
    }
    a %= b;
  }

  cout << -1;
  return 0;
}
