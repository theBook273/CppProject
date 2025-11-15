#include <bits/stdc++.h>
#include <climits>
#include <queue>
#define int long long

using namespace std;

const int INF = 1e18;
const pair<int, int> moveSet[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const pair<int, int> around[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                 {0, 1},   {1, -1}, {1, 0},  {1, 1}};
int n, m, k;
vector<vector<bool>> board;
vector<vector<int>> dis;

bool inR(int x, int y, int a, int b, int r) {
  return ((a - x) * (a - x) + (b - y) * (b - y) <= r * r);
}

bool valid(int x, int y) { return (1 <= x && x <= n && 1 <= y && y <= m); }

void buildBlock(int x, int y, int r) {
  queue<pair<int, int>> q;
  q.push({x, y});
  board[x][y] = 1;
  while (!q.empty()) {
    auto [a, b] = q.front();
    q.pop();
    for (auto &[movex, movey] : around) {
      int nx = a + movex;
      int ny = b + movey;
      if (valid(nx, ny) && board[nx][ny] == 0 && inR(x, y, nx, ny, r)) {
        board[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
}

int letsGo() {
  if (board[1][1] == 1) {
    return -1;
  }
  queue<pair<int, int>> q;
  q.push({1, 1});
  board[1][1] = 1;
  dis[1][1] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto [movex, movey] : moveSet) {
      int nx = x + movex;
      int ny = y + movey;
      if (valid(nx, ny) && board[nx][ny] == 0) {
        dis[nx][ny] = dis[x][y] + 1;
        board[nx][ny] = 1;
        if (nx == n && ny == m) {
          return dis[nx][ny];
        }
        q.push({nx, ny});
      }
    }
  }
  return -1;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m >> k;
  board.resize(n + 2, vector<bool>(m + 2, 1));
  dis.resize(n + 2, vector<int>(m + 2, INF));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      board[i][j] = 0;
    }
  }

  for (int x, y, r, i = 0; i < k; i++) {
    cin >> x >> y >> r;
    buildBlock(x, y, r);
  }

  cout << letsGo();
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     cout << board[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n\n";
}
