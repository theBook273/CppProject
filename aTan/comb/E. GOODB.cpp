#include <bits/stdc++.h>
#define int long long

using namespace std;

class combination {
private:
  const int MOD = 1e9 + 7;
  const int N = 3e6;
  vector<int> f, fi;

public:
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
    return res % MOD;
  }

  int inv(int x) { return (binPow(x, MOD - 2)); }

  combination() {
    f.resize(N + 1, 0);
    fi.resize(N + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
      f[i] = mul(f[i - 1], i);
    }
    fi[N] = inv(f[N]);
    for (int i = N; i >= 1; i--) {
      fi[i - 1] = mul(fi[i], i);
    }
  }
  int C(int a, int b) { return mul(f[a], mul(fi[b], fi[a - b])); }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  combination calc;

  int n, wa, tle, rte;
  cin >> n >> wa >> tle >> rte;

  int a = calc.C(n, wa);
  int b = calc.C(n - wa, tle);

  cout << calc.mul(a, b);
}
