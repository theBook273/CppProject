#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1005;

pair<int, int> moveSet[] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                            {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int n, m, q, r, c, k;
bool board[MAXN][MAXN];

bool valid(int x, int y) { return (1 <= x && x <= n && 1 <= y && y <= m); }

int bfs(int x, int y, int num) {
  int vis[n + 5][m + 5];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      vis[i][j] = 1e9;
    }
  }

  int res = 0, dem = (board[x][y] == 1);
  queue<pair<int, int>> q;
  q.push({x, y});
  vis[x][y] = 1;

  if (dem == num) {
    return res;
  }

  while (!q.empty()) {
    auto [nowx, nowy] = q.front();
    q.pop();
    for (auto [movex, movey] : moveSet) {
      int tempx = nowx + movex;
      int tempy = nowy + movey;
      if (valid(tempx, tempy) && vis[tempx][tempy] > vis[nowx][nowy] + 1) {
        vis[tempx][tempy] = vis[nowx][nowy] + 1;
        q.push({tempx, tempy});
        if (board[tempx][tempy] == 1) {
          res += vis[tempx][tempy] * 2 - 2;
          dem++;
          if (dem == num) {
            return res;
          }
        }
      }
    }
  }

  return res;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  // freopen("THAMHIEM.inp", "r", stdin);
  // freopen("THAMHIEM.out", "w", stdout);

  cin >> n >> m;
  string temp;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    for (int j = 1; j <= m; j++) {
      board[i][j] = (temp[j - 1] == '1');
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     cout << board[i][j];
  //   }
  //   cout << "\n";
  // }

  cin >> q;
  while (q--) {
    cin >> r >> c >> k;
    cout << bfs(r, c, k) << "\n";
  }
}
