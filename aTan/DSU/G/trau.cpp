#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;

int n, m, q;
vector<vector<int>> board;

pair<int, int> moveSet[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool valid(int x, int y) { return (1 <= x && x <= n && 1 <= y && y <= m); }

void dfs(int x, int y, int ask, vector<vector<bool>> &visited) {
  visited[x][y] = true;
  for (auto [dx, dy] : moveSet) {
    int nx = x + dx, ny = y + dy;
    if (valid(nx, ny) && !visited[nx][ny] && board[nx][ny] > ask)
      dfs(nx, ny, ask, visited);
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("test.inp", "r", stdin);
  freopen("testTrau", "w", stdout);

  cin >> n >> m;
  board.resize(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> board[i][j];

  cin >> q;
  vector<int> ask(q);
  for (int i = 0; i < q; i++)
    cin >> ask[i];

  for (int k = 0; k < q; k++) {
    int curAsk = ask[k];
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    int region = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!visited[i][j] && board[i][j] > curAsk) {
          region++;
          dfs(i, j, curAsk, visited);
        }
      }
    }

    cout << region << "\n";
  }
}
