#include <bits/stdc++.h>
#define int long long
using namespace std;

double frac(int x) {
  int res = 1;
  for (int i = 1; i <= x; i++) {
    res *= i;
  }
  return res;
}

signed main() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += ((((n % i == 0) ? i : 1) % 2 == 0) ? i : 0);
  }
  cout << res;
}
