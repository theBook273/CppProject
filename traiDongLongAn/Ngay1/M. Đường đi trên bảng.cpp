#include <bits/stdc++.h>

using namespace std;

const int MOD(1e7 + 1203);
const int N(1e4);
const pair<int, int> moveSet[] = {{-1, 0}, {0, -1}};

int n, m, p, q;

bool valid(int x, int y) { return (0 <= x && x < n && 0 <= y && y < m); }
int add(int x, int y) { return ((x % MOD) + (y % MOD)) % MOD; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("walk.inp", "r", stdin);
  freopen("walk.out", "w", stdout);

  cin >> n >> m >> p >> q;

  vector<vector<int>> board(n + 5, vector<int>(m + 5, 0));

  while (p--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    board[u][v] = -1;
  }

  board[0][0] = 1;
  for (int j = 1; j < m; j++) {
    if (board[0][j] != -1) {
      board[0][j] = 1;
    } else {
      break;
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] != -1) {
        for (auto &[movex, movey] : moveSet) {
          int px = i + movex;
          int py = j + movey;
          if (valid(px, py) && board[px][py] != -1) {
            board[i][j] = add(board[i][j], board[px][py]);
          }
        }
      }
    }
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << board[u][v] << " ";
  }
}
