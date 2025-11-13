#include <bits/stdc++.h>
#define int long long

using namespace std;

const pair<int, int> moveSet[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<vector<char>> board;
set<pair<int, int>> ice;
vector<int> dsu;
vector<bool> active;
pair<int, int> st = {0, 0}, en = {0, 0};
int n, m;

int convert(int x, int y) { return (x - 1) * m + y; }
int acs(int x) { return (dsu[x] == x ? x : dsu[x] = acs(dsu[x])); }

void join(int x, int y) {
  x = acs(x);
  y = acs(y);

  if (x != y) {
    dsu[y] = x;
  }
}

bool valid(int x, int y) { return (1 <= x && x <= n && 1 <= y && y <= m); }

void melt() {
  vector<pair<int, int>> toMelt;
  for (auto [i, j] : ice) {
    int u = convert(i, j);
    active[u] = 1;
    board[i][j] = '.';

    for (auto [movex, movey] : moveSet) {
      int nx = i + movex;
      int ny = j + movey;

      if (valid(nx, ny)) {
        if (board[nx][ny] == '.') {
          int v = convert(nx, ny);
          if (active[v]) {
            join(u, v);
          }
        } else {
          toMelt.push_back({nx, ny});
        }
      }
    }
  }

  for (auto i : toMelt) {
    ice.insert(i);
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test", "r", stdin);
  freopen("testChuan", "w", stdout);

  cin >> n >> m;

  board.resize(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'L') {
        board[i][j] = '.';
        if (st.first == 0 && st.second == 0) {
          st = {i, j};
        } else {
          en = {i, j};
        }
      }
    }
  }

  dsu.resize(n * m + 5);
  active.resize(n * m + 5, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int u = convert(i, j);
      dsu[u] = u;
      active[u] = (board[i][j] == '.');

      if (board[i][j] == '.') {
        for (auto [movex, movey] : moveSet) {
          int nx = i + movex;
          int ny = j + movey;

          if (valid(nx, ny) && board[nx][ny] == 'X') {
            ice.insert({nx, ny});
          }
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (board[i][j] == '.') {
        for (auto [movex, movey] : moveSet) {
          int nx = i + movex;
          int ny = j + movey;

          if (valid(nx, ny) && board[nx][ny] == '.') {
            int u = convert(i, j);
            int v = convert(nx, ny);
            join(u, v);
          }
        }
      }
    }
  }

  int dem = 0;
  int u = convert(st.first, st.second);
  int v = convert(en.first, en.second);
  while (acs(u) != acs(v)) {
    melt();
    dem++;

    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= m; j++) {
    //     // cout << acs(convert(i, j)) << " ";
    //     cout << board[i][j];
    //   }
    //   cout << "\n";
    // }
    // cout << "\n\n";
  }

  cout << dem << "\n";
}
