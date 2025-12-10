#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("CHIAKEO.INP", "r", stdin);
  freopen("CHIAKEO.OUT", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  int totalState = 1;
  for (int i = 0; i < n; i++) {
    totalState *= 3;
  }

  for (int mask = 0; mask < totalState; mask++) {
    int x = mask;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
      int t = x % 3;
      x /= 3;
      if (t == 1) {
        s1 += a[i];
      } else if (t == 2) {
        s2 += a[i];
      }
    }
    if (s1 == s2 && s1 > 0) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
  return 0;
}
