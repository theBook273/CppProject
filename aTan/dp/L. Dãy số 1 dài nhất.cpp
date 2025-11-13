#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n), left(n, 0), right(n, 0);
  for (int &i : a) {
    cin >> i;
  }

  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      left[i] = (i ? left[i - 1] : 0) + a[i];
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
      right[i] = (i < n - 1 ? right[i + 1] : 0) + a[i];
    }
  }

  int res = 0;
  for (int i = 1; i < n - 1; i++) {
    res = max(res, left[i - 1] + right[i + 1]);
  }
  cout << res;
}
