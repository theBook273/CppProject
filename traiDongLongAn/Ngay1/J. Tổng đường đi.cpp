#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 998244353;
const pair<int, int> moveSet[] = {{-1, 0}, {0, -1}, {-1, -1}};

vector<vector<int>> a, way, value;
int n, m;

int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
bool valid(int x, int y) { return ((0 <= x && x < n && 0 <= y && y < m)); }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("sumpath.inp", "r", stdin);
  freopen("sumpath.out", "w", stdout);

  cin >> n >> m;
  a.resize(n, vector<int>(m));
  way.resize(n, vector<int>(m, 0));
  value.resize(n, vector<int>(m, 0));

  for (auto &i : a) {
    for (auto &j : i) {
      char temp;
      cin >> temp;
      j = temp - '0';
    }
  }

  way[0][0] = 1;
  value[0][0] = a[0][0];

  for (int j = 1; j < m; j++) {
    way[0][j] = 1;
    value[0][j] = value[0][j - 1] + a[0][j] * way[0][j];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (auto &[x, y] : moveSet) {
        int px = i + x;
        int py = j + y;
        if (valid(px, py)) {
          way[i][j] = add(way[i][j], way[px][py]);
        }
      }

      for (auto &[x, y] : moveSet) {
        int px = i + x;
        int py = j + y;
        if (valid(px, py)) {
          value[i][j] = add(value[i][j], value[px][py]);
        }
      }

      value[i][j] =
          (value[i][j] % MOD + ((a[i][j] % MOD) * (way[i][j] % MOD)) % MOD) %
          MOD;
    }
  }

  cout << value[n - 1][m - 1];
}
