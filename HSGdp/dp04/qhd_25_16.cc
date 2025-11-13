#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1005;

int board[MAXN][MAXN], mn[MAXN][MAXN], mx[MAXN][MAXN];

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("GAME.INP", "r", stdin);
  freopen("GAME.OUT", "w", stdout);

  int n, m, point, ansMx = LLONG_MIN, ansMn = LLONG_MAX;
  cin >> n >> m >> point;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
  }

  for (int j = 1; j <= m; j++) {
    mx[1][j] = mn[1][j] = board[1][j] + point;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int toPlus = LLONG_MIN;
      for (int k = -1; k <= 1; k++) {
        int c = j + k;
        if (1 <= c && c <= m) {
          toPlus = max(toPlus, mx[i - 1][c]);
        }
      }
      if (board[i][j] == 0) {
        toPlus = ceil(toPlus / 2.0);
      }
      mx[i][j] = board[i][j] + toPlus;
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int toPlus = LLONG_MAX;
      for (int k = -1; k <= 1; k++) {
        int c = j + k;
        if (1 <= c && c <= m) {
          toPlus = min(toPlus, mn[i - 1][c]);
        }
      }
      if (board[i][j] == 0) {
        toPlus = ceil(toPlus / 2.0);
      }
      mn[i][j] = board[i][j] + toPlus;
    }
  }

  for (int j = 1; j <= m; j++) {
    ansMx = max(ansMx, mx[n][j]);
    ansMn = min(ansMn, mn[n][j]);
  }
  cout << ansMn << "\n" << ansMx;
}
