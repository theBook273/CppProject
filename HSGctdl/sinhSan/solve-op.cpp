#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

struct matrix {
  int m[2][2];
};

matrix mul(matrix a, matrix b) {
  matrix res;

  res.m[0][0] =
      ((a.m[0][0] * b.m[0][0]) % MOD + (a.m[0][1] * b.m[1][0]) % MOD) % MOD;

  res.m[0][1] =
      ((a.m[0][0] * b.m[0][1]) % MOD + (a.m[0][1] * b.m[1][1]) % MOD) % MOD;

  res.m[1][0] =
      ((a.m[1][0] * b.m[0][0]) % MOD + (a.m[1][1] * b.m[1][0]) % MOD) % MOD;

  res.m[1][1] =
      ((a.m[1][0] * b.m[0][1]) % MOD + (a.m[1][1] * b.m[1][1]) % MOD) % MOD;

  return res;
}

matrix binPow(matrix a, int b) {
  matrix res = {{{1, 0}, {0, 1}}};

  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }

  return res;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;

  matrix M = {{{1, 1}, {1, 0}}}, temp = {{{1}, {1}}};
  M = binPow(M, n + 1);
  matrix res = mul(M, temp);

  cout << (res.m[0][0] - 1) % MOD;
}
