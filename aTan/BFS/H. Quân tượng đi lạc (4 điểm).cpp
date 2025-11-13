#include <bits/stdc++.h>

using namespace std;

pair<int, int> moveSet[] = {{-2, -2}, {-2, +2}, {2, -2}, {2, 2}};
int a, b, x, y;
int board[9][9];

bool valid(int x, int y) { return (1 <= x && x <= 8 && 1 <= y && y <= 8); }

void bfs() {
  queue<pair<int, int>> pos;
  pos.push({a, b});
  board[a][b] = 0;
  while (!pos.empty()) {
    int tempx = pos.front().first;
    int tempy = pos.front().second;
    pos.pop();
    for (auto [movex, movey] : moveSet) {
      int nowx = movex + tempx;
      int nowy = movey + tempy;
      if (board[nowx][nowy] == -1 && valid(nowx, nowy)) {
        board[nowx][nowy] = board[tempx][tempy] + 1;
        if (nowx == x && nowy == y) {
          return;
        }
        pos.push({nowx, nowy});
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> a >> b >> x >> y;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      board[i][j] = -1;
    }
  }
  bfs();
  // for (int i = 1; i <= 8; i++) {
  //   for (int j = 1; j <= 8; j++) {
  //     cout << (board[i][j] == -1 ? 0 : board[i][j]) << " ";
  //   }
  //   cout << "\n";
  // }
  cout << board[x][y];
}
