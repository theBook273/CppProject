#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 500;
const int oo = 1e18;
const pair<int, int> moveSet[] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int n, m, dinh = 0;
int h[N + 5][N + 5], hole[N + 5][N + 5];
vector<vector<bool>> vis;
pair<int, int> start;

bool valid(int x, int y) {
  return (1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y]);
}

bool bfs(pair<int, int> start, int d) {
  queue<pair<int, int>> q;
  q.push(start);
  vis[start.first][start.second] = 1;
  int dem = 1;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (auto [a, b] : moveSet) {
      int nx = x + a;
      int ny = y + b;
      if (valid(nx, ny) && abs(h[x][y] - h[nx][ny]) <= d) {
        vis[nx][ny] = 1;
        q.push({nx, ny});
        dem += hole[nx][ny];
      }
    }
  }

  return dem == dinh;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> h[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> hole[i][j];
      if (hole[i][j] == 1) {
        dinh++;
        start = {i, j};
      }
    }
  }

  int l = 1, r = 1e9;
  int res = oo;
  while (l <= r) {
    int mid = (l + r) >> 1;
    vis.assign(n + 1, vector<bool>(m + 1, 0));
    if (bfs(start, mid)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << res;
}
