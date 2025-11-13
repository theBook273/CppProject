#include <bits/stdc++.h>

using namespace std;

const pair<int, int> moveSet[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
vector<vector<char>> board;
vector<vector<bool>> vis;
pair<int, int> pos1 = {0, 0}, pos2 = {0, 0};

bool valid(int x, int y) { return (1 <= x && x <= n && 1 <= y && y <= m); }

void melt() {
  vector<pair<int, int>> toMelt;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (board[i][j] == '.' || board[i][j] == 'L') {
        for (auto [movex, movey] : moveSet) {
          int nx = i + movex;
          int ny = j + movey;
          if (valid(nx, ny) && board[nx][ny] == 'X') {
            toMelt.push_back({nx, ny});
          }
        }
      }
    }
  }
  for (auto [i, j] : toMelt) {
    board[i][j] = '.';
  }
}

bool reached() {
  vis.assign(n + 1, vector<bool>(m + 1, 0));
  queue<pair<int, int>> q;
  q.push(pos1);
  vis[pos1.first][pos1.second] = 1;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto [movex, movey] : moveSet) {
      int nx = x + movex;
      int ny = y + movey;
      if (valid(nx, ny) && !vis[nx][ny] && board[nx][ny] != 'X') {
        if (nx == pos2.first && ny == pos2.second) {
          return 1;
        }
        vis[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }

  return 0;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test", "r", stdin);
  freopen("testTrau", "w", stdout);

  cin >> n >> m;
  board.resize(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'L') {
        if (pos1.first == 0 && pos1.second == 0) {
          pos1 = {i, j};
        } else {
          pos2 = {i, j};
        }
      }
    }
  }

  int dem = 0;
  while (!reached()) {
    melt();
    dem++;
    vis.assign(n + 1, vector<bool>(m + 1, 0));
  }
  cout << dem << "\n";
}
