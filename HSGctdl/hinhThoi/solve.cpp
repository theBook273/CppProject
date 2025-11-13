#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2008;

struct Tam {
  int x, y, heSo;
};

pair<int, int> moveT[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
pair<int, int> moveC[] = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}};

vector<Tam> tam;
char a[MAXN][MAXN];
int n, m;

void checkTam(int x, int y) {
  for (int i = 1; i <= max(m, n); i++) {
    char mau = a[x + i * moveT[0].first][y + i * moveT[0].second];
    for (auto [hex, hey] : moveT) {
      if (mau != a[x + i * hex][y + i * hey]) {
        return;
      }
    }
    if (mau == '#') {
      tam.push_back({x, y, i});
      return;
    }
  }
}

bool khepKin(Tam cen, int heSo, char check) {
  int x = cen.x - 1 * heSo;
  int y = cen.y;
  for (auto [hex, hey] : moveC) {
    for (int i = 0; i < heSo; i++) {
      x += hex;
      y += hey;
      if (a[x][y] != check) {
        return 0;
      }
    }
  }
  return 1;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      a[i][j] = '.';
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      checkTam(i, j);
    }
  }

  // for (auto [x, y, he] : tam) {
  //   cout << x << " " << y << " " << he << "\n";
  // }
  int tong = 0;

  for (auto i : tam) {
    if (khepKin(i, i.heSo, '#') && khepKin(i, i.heSo + 1, '.')) {
      tong++;
    }
  }

  cout << tong;
}
