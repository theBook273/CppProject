#include <bits/stdc++.h>

using namespace std;

pair<int, int> movement[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
char a[501][501];

bool valid(int a, int b) { return (0 <= a && a < n && 0 <= b && b <= m); }

signed main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') {
        for (auto [x, y] : movement) {
          int moveTox = i + x;
          int moveToy = j + y;
          if (valid(moveTox, moveToy) && a[moveTox][moveToy] == '.') {
            a[moveTox][moveToy] = 'D';
          } else if (valid(moveTox, moveToy) && a[moveTox][moveToy] == 'W') {
            cout << "No\n";
            return 0;
          }
        }
      }
    }
  }

  cout << "Yes\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << "\n";
  }
}
