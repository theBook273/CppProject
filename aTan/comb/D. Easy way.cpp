#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e6;

int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }

int binPow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int inv(int a) { return (binPow(a, MOD - 2) % MOD); }

int f[N + 5], fi[N + 5];

void init() {
  f[0] = 1;
  for (int i = 1; i <= N; i++) {
    f[i] = mul(f[i - 1], i);
  }
  fi[N] = inv(f[N]);
  for (int i = N; i >= 1; i--) {
    fi[i - 1] = mul(fi[i], i);
  }
}

int C(int a, int b) { return (mul(f[a], mul(fi[b], fi[a - b])) % MOD); }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int doc = x2 - x1;
  int ngang = y2 - y1;

  // cout << doc << " " << ngang << endl;

  cout << C(doc + ngang, ngang);
}
