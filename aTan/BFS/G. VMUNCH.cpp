#include <bits/stdc++.h>

using namespace std;

const int MAXN = 550;

pair<int, int> moveSet[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;
char board[MAXN][MAXN];
int dem[MAXN][MAXN];
pair<int, int> pos;

void bfs() {
  dem[pos.first][pos.second] = 1;
  queue<pair<int, int>> q;
  q.push(pos);
  board[pos.first][pos.second] = '*';
  dem[pos.first][pos.second] = 1;
  while (!q.empty()) {
    pair<int, int> temp = q.front();
    q.pop();
    for (auto [x, y] : moveSet) {
      int nowx = temp.first + x;
      int nowy = temp.second + y;
      if (board[nowx][nowy] == '.') {
        board[nowx][nowy] = '*';
        if (nowx == 1 && nowy == 1) {
          dem[nowx][nowy] = dem[temp.first][temp.second];
          return;
        }
        dem[nowx][nowy] = dem[temp.first][temp.second] + 1;
        q.push({nowx, nowy});
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;

  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      board[i][j] = '*';
      dem[i][j] = -1;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'C') {
        pos = {i, j};
      }
    }
  }

  board[1][1] = '.';
  bfs();
  cout << dem[1][1];
}
