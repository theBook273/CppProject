#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  freopen("test.inp", "r", stdin);
  freopen("chuan.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == k) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}
