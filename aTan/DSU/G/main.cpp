#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Query {
  int ask, id;
};

struct Cell {
  int val, x, y;
};

pair<int, int> moveSet[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> board;
vector<Query> query;
vector<int> dsu, ans;
vector<bool> active;
vector<Cell> cell;
int n, m, q, vung = 0;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }

void join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    dsu[y] = x;
    vung--;
  }
}

int convert(int x, int y) { return (x - 1) * m + y; }

bool compQue(Query a, Query b) { return a.ask > b.ask; }

bool compCell(Cell a, Cell b) { return a.val > b.val; }

bool valid(int x, int y) { return (1 <= x && x <= n && 1 <= y && y <= m); }

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test.inp", "r", stdin);
  freopen("testChuan", "w", stdout);

  cin >> n >> m;

  board.resize(n + 1, vector<int>(m + 1));
  dsu.resize(n * m + 5);
  active.resize(n * m + 5, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
      dsu[convert(i, j)] = convert(i, j);
      cell.push_back({board[i][j], i, j});
    }
  }

  cin >> q;
  query.resize(q);
  ans.resize(q + 1, 0);
  for (int i = 0; i < q; i++) {
    cin >> query[i].ask;
    query[i].id = i;
  }

  sort(query.begin(), query.end(), compQue);
  sort(cell.begin(), cell.end(), compCell);

  int index = 0;
  for (auto [ask, id] : query) {
    while (index < (int)cell.size() && cell[index].val > ask) {
      int x = cell[index].x, y = cell[index].y;
      int u = convert(x, y);
      active[u] = 1;
      vung++;

      for (auto [movex, movey] : moveSet) {
        int nx = x + movex;
        int ny = y + movey;
        if (valid(nx, ny)) {
          int v = convert(nx, ny);
          if (active[v]) {
            join(u, v);
          }
        }
      }
      index++;
    }
    ans[id] = vung;
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
}
