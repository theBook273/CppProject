#include <bits/stdc++.h>

using namespace std;

pair<int, int> moveSet[] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                            {1, -2},  {1, 2},  {2, -1},  {2, 1}};
int n, m, a, b, x, y;
int board[1001][1001];

bool valid(int x, int y) {
  return (1 <= x && x <= n && 1 <= y && y <= m && board[x][y] == -1);
}

void bfs() {
  queue<pair<int, int>> q;
  q.push({a, b});
  board[a][b] = 0;
  while (!q.empty()) {
    int nowx = q.front().first;
    int nowy = q.front().second;
    q.pop();
    for (auto [movex, movey] : moveSet) {
      int tempx = nowx + movex;
      int tempy = nowy + movey;
      if (valid(tempx, tempy)) {
        board[tempx][tempy] = board[nowx][nowy] + 1;
        if (tempx == x && tempy == y) {
          return;
        }
        q.push({tempx, tempy});
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m >> a >> b >> x >> y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      board[i][j] = -1;
    }
  }
  bfs();
  cout << board[x][y];
}
