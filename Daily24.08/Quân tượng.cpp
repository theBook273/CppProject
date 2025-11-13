#include <bits/stdc++.h>

using namespace std;

int board[209][209];

signed main() {
  cin.tie()->sync_with_stdio(0);

  int n, m, p, q, s, t;
  cin >> n >> m >> p >> q >> s >> t;

  for (int j = 1; j <= n; j++) {
    board[1][j] = (j % 2);
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      board[i][j] = !(board[i - 1][j]);
    }
  }

  while (m--) {
    int x, y;
    cin >> x >> y;
    board[x][y] = 7;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}
