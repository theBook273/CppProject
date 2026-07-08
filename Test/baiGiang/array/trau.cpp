#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  freopen("test.inp", "r", stdin);
  freopen("trau.out", "w", stdout);

  int n, k;
  bool check = false;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= (n - 1); i++) {
    if (a[i] == k) {
      cout << i;
      check = true;
      break;
    }
  }
  if (check == false) {
    cout << "-1";
  }
}
