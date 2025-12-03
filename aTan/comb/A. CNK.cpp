#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

vector<int> fi(N, 0);
vector<int> f(N, 0);

int mul(int a, int b) { return ((a % MOD) * (b % MOD) % MOD); }

int binPow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int inv(int x) { return binPow(x, MOD - 2) % MOD; }

void init() {
  f[0] = 1;
  for (int i = 1; i <= N; i++) {
    f[i] = mul(i, f[i - 1]);
  }

  fi[N] = inv(f[N]);
  for (int i = N; i >= 1; i--) {
    fi[i - 1] = mul(fi[i], i);
  }
}

int C(int a, int b) { return mul(f[a], mul(fi[b], fi[a - b])); }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  int a, b, n;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    cout << C(a, b) << "\n";
  }
}
