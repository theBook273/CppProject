#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  bool root[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      root[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    if (a[i][0] == '1') {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '1') {
          root[i][j] = 1;
        } else {
          break;
        }
      }
    }
  }

  for (int j = 0; j < m; j++) {
    if (a[0][j] == '1') {
      for (int i = 0; i < n; i++) {
        if (a[i][j] == '1') {
          root[i][j] = 1;
        } else {
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (root[i][j] != a[i][j] - '0') {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
