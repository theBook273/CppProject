#include <bits/stdc++.h>
#include <queue>
#define int long long

using namespace std;

const int N = 1000;
const int oo = 1e18;

pair<int, int> start, moveSet[] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int n, m, k, tong = 0, giu = 0;
int a[N + 5][N + 5], dis[N + 5][N + 5];

bool valid(int x, int y) {
  return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == 1);
}

void bfs(pair<int, int> start) {
  queue<pair<int, int>> q;
  q.push(start);
  dis[start.first][start.second] = 0;
  giu--;

  if (giu == 0) {
    return;
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto [a, b] : moveSet) {
      int nx = x + a;
      int ny = y + b;
      if (valid(nx, ny) && dis[nx][ny] > dis[x][y] + 1) {
        dis[nx][ny] = dis[x][y] + 1;
        q.push({nx, ny});
        giu--;
        if (giu == 0) {
          return;
        }
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      dis[i][j] = oo;
      if (a[i][j] == 1) {
        start = {i, j};
        tong++;
      }
    }
  }

  giu = tong - k;

  bfs(start);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dis[i][j] == oo && a[i][j] == 1) {
        cout << i << " " << j << "\n";
      }
    }
  }
}
