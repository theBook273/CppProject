#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("watermelon.inp", "r", stdin);
  freopen("watermelon.out", "w", stdout);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    if (i % 2 == 0 && (n - i) % 2 == 0) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
