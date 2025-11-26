#include <bits/stdc++.h>
#define int long long
#define bit(x, i) (((x) >> (i)) & 1)
#define mask(x) (1LL << (x))

using namespace std;

const int MOD = (int)1e9 + 7;

int n, m;
vector<bool> ok;
vector<vector<int>> f;

void add(int &x, int &y) {
  x += y;
  if (x >= MOD) {
    x -= MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  swap(n, m);
  int full = mask(m);

  ok.resize(full + 2, 0);
  f.resize(n + 1, vector<int>(full, 0));
  ok[0] = 1;

  for (int mask = 0; mask < full; mask++) {
    if (ok[mask]) {
      for (int j = 0; j < m - 1; j++) {
        if (!bit(mask, j) && !bit(mask, j + 1)) {
          ok[mask | mask(j) | mask(j + 1)] = 1;
        }
      }
    }
  }

  f[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < full; mask++) {
      if (f[i][mask] > 0) {
        for (int newmask = (full - 1) ^ mask; newmask >= 0; newmask--) {
          newmask &= (full - 1) ^ mask;
          int curmask = (full - 1) ^ (mask | newmask);
          if (ok[curmask]) {
            add(f[i + 1][newmask], f[i][mask]);
          }
        }
      }
    }
  }

  cout << f[n][0];
}
