#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  freopen("bitsum.inp", "r", stdin);
  freopen("bitsum.out", "w", stdout);

  int n;
  cin >> n;

  int res = 0;

  for (int i = 1; i <= n; i++) {
    int temp = i;
    while (temp > 0) {
      res += (temp & 1);
      temp >>= 1;
    }
  }

  cout << res;
}
