#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 998244353;

vector<vector<int>> a, f, g;
int n, m;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  freopen("sumpath.inp", "r", stdin);
  freopen("sumpath.out", "w", stdout);

  cin >> n >> m;

  a.resize(n + 1, vector<int>(m + 1, 0));
  f.resize(n + 1, vector<int>(m + 1, 0));
  g.resize(n + 1, vector<int>(m + 1, 0));

  char temp;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> temp;
      a[i][j] = temp - '0';
    }
  }

  f[1][1] = 1;
  g[1][1] = a[1][1];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1) {
        continue;
      }

      f[i][j] = (f[i - 1][j] + f[i][j - 1] + f[i - 1][j - 1]) % MOD;
      g[i][j] = (g[i - 1][j] + g[i][j - 1] + g[i - 1][j - 1] +
                 (a[i][j] * f[i][j]) % MOD) %
                MOD;
    }
  }

  cout << g[n][m] % MOD;
}
