#include <bits/stdc++.h>

using namespace std;
char a[109][109];
char check[109][109];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      check[i][j] = '0';
    }
  }

  for (int i = 0; i < n; i++) {
    check[i][n - 1] = a[i][n - 1];
  }
  for (int j = 0; j < n; j++) {
    check[n - 1][j] = a[n - 1][j];
  }

  for (int i = 0; i < n; i++) {
    for (int j = n - 2; j >= 0; j--) {
      if (a[i][j] == '1' && check[i][j] == '0') {
        if (a[i][j + 1] != '1') {
          break;
        } else {
          check[i][j] = '1';
        }
      }
    }
  }

  for (int j = 0; j < n; j++) {
    for (int i = n - 2; i >= 0; i--) {
      if (a[i][j] == '1' && check[i][j] == '0') {
        if (a[i + 1][j] != '1') {
          break;
        } else {
          check[i][j] = '1';
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = n - 2; j >= 0; j--) {
      if (a[i][j] == '1' && check[i][j] == '0') {
        if (a[i][j + 1] != '1') {
          break;
        } else {
          check[i][j] = '1';
        }
      }
    }
  }

  for (int j = 0; j < n; j++) {
    for (int i = n - 2; i >= 0; i--) {
      if (a[i][j] == '1' && check[i][j] == '0') {
        if (a[i + 1][j] != '1') {
          break;
        } else {
          check[i][j] = '1';
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != check[i][j]) {
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
