#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> c;
vector<vector<vector<int>>> f;
int n;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("cake.INP", "r", stdin);
  freopen("cake.OUT", "w", stdout);

  cin >> n;

  c.resize(n + 1, vector<int>(n + 1));
  f.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(2)));

  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }

  f[0][n][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int z = 0; z <= j; z++) {
        if (z == i) {
          f[i][j - z][1] += (((f[i - 1][j][0] * c[j][z]) % MOD) +
                             ((f[i - 1][j][1] * c[j][z]) % MOD)) %
                            MOD;
        }

        else {
          f[i][j - z][0] = (f[i][j - z][0] + (f[i - 1][j][0] * c[j][z])) % MOD;
          f[i][j - z][1] = (f[i][j - z][1] + (f[i - 1][j][1] * c[j][z])) % MOD;
        }
      }
    }
  }

  cout << f[n][0][1] << "\n";
}
