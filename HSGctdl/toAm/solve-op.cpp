#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

int n;

struct matrix {
  int a[2][2];
};

matrix mul(matrix x, matrix y) {
  matrix c{};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      c.a[i][j] = (x.a[i][0] * y.a[0][j] + x.a[i][1] * y.a[1][j]) % MOD;
    }
  }

  return c;
}

matrix binPow(matrix a, int b) {
  matrix res = {{{1, 0}, {0, 1}}};
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
  cin >> n;

  if (n == 1) {
    cout << 1;
    return 0;
  }
  if (n == 2) {
    cout << 3;
    return 0;
  }

  matrix m = {{{1, 2}, {1, 0}}};
  matrix p = binPow(m, n - 2);
  cout << (p.a[0][0] * 3 + p.a[0][1] * 1) % MOD << "\n";
}
