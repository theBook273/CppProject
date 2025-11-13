#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;

  vector<int> dayTang(n, 1), a(n), dayGiam(n, 1);
  for (auto &i : a)
    cin >> i;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        dayTang[i] = max(dayTang[i], dayTang[j] + 1);
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j > i; j--) {
      if (a[i] > a[j]) {
        dayGiam[i] = max(dayGiam[i], dayGiam[j] + 1);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, 2 * min(dayGiam[i], dayTang[i]) - 1);
  }
  cout << ans;
}
