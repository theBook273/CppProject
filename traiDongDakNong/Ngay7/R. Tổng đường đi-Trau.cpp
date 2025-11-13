#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int MAXN = 2207;

const pair<int, int> moveSet[] = {{1, 0}, {0, 1}, {1, 1}};
vector<vector<int>> board(MAXN + 1, vector<int>(MAXN + 2, -1));
int n, m, tong = 0;

bool valid(int x, int y) { return board[x][y] != -1; }

void brute(int upToNow, int x, int y) {
  if (x == n && y == m) {
    tong += upToNow;
    return;
  }
  for (auto [a, b] : moveSet) {
    int nextX = x + a;
    int nextY = y + b;
    if (valid(nextX, nextY)) {
      int next = upToNow + board[nextX][nextY];
      brute(next, nextX, nextY);
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  char temp;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> temp;
      board[i][j] = temp - '0';
    }
  }

  brute(board[1][1], 1, 1);
  cout << tong;
}
