#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("test.inp", "r", stdin);
  freopen("chuan.out", "w", stdout);

  int res = -1;

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  for (int i = 0; i < n - 1; i++) {
    if ((a[i] & 1 && !(a[i + 1] & 1)) || (!(a[i] & 1) && (a[i + 1] & 1))) {
      res = max(res, a[i] + a[i + 1]);
    }
  }

  cout << res;
}
