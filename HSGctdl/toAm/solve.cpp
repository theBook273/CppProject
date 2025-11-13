#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  int a = 1;
  int b = 3;
  if (n == 1) {
    cout << a << "\n";
    return 0;
  }
  if (n == 2) {
    cout << b << "\n";
    return 0;
  }
  int res = 0;

  for (int i = 3; i <= n; i++) {
    res = (b + a * 2) % MOD;
    a = b;
    b = res;
  }
  cout << res << "\n";
}
