#include <bits/stdc++.h>
#define int long long

using namespace std;

struct matrix {
  int m[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
};

int n, mod;

matrix mul(matrix a, matrix b) {
  matrix res;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
      }
    }
  }

  return res;
}

matrix binPow(matrix a, int b) {
  matrix res = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};

  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }

  return res;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> mod;

  matrix transit = {{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}};
  matrix base = {{{4}, {2}, {1}}};

  matrix res = mul(binPow(transit, n - 3), base);

  cout << res.m[0][0] % mod;
}
