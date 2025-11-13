#include <bits/stdc++.h>

using namespace std;

pair<int, int> step[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int a[501][501];

void solve() {
  int n;
  cin >> n;
  int dem = n * n - 1, id = 0;
  int x, y;
  x = y = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = -1;
    }
  }

  for (int i = 0; i < n * n; i++) {
    a[x][y] = dem;
    dem--;

    int tempx = x + step[id].first;
    int tempy = y + step[id].second;

    while ((tempx >= n || tempy >= n || tempx < 0 || tempy < 0 ||
            a[tempx][tempy] != -1) &&
           dem >= 0) {
      id++;
      id %= 4;
      tempx = x + step[id].first;
      tempy = y + step[id].second;
    }

    x = tempx;
    y = tempy;
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
