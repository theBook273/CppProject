#include <bits/stdc++.h>

using namespace std;

pair<int, int> step[] = {{1, 0}, {0, 1}, {1, 1}};

void solve() {
  int n;
  cin >> n;

  int a[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }

  int x = (n - 1) / 2;
  a[x][x] = 0;

  for (int i = 0; i < 3; i++) {
    int movex = step[i].first + x;
    int movey = step[i].second + x;
    if (movex < n && movey < n) {
      a[x + step[i].first][x + step[i].second] = i + 1;
    }
  }

  int dem = 4;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0 && (i != x || j != x)) {
        if (i == 0 && j == 0) {
          a[i][j] = n * n - 1;
          continue;
        }
        a[i][j] = dem;
        dem++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
