#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int MOD = 1e9 + 7;

int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }

int binPow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    b >>= 1;
    a = mul(a, a);
  }
  return res;
}

int inv(int a) { return binPow(a, MOD - 2) % MOD; }

vector<int> f(N + 1, 0), fi(N + 1, 0);

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

int C(int a, int b) { return mul(f[a], mul(fi[b], fi[a - b])); }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  int n;
  cin >> n;
  vector<int> a;
  for (int x, i = 1; i <= n; i++) {
    cin >> x;
    if (x == 1) {
      a.push_back(i);
    }
  }

  if (a.size() == 0) {
    cout << a.size();
    return 0;
  }

  int res = 1;

  for (int i = 0; i < (int)a.size() - 1; i++) {
    res = mul(res, (a[i + 1] - a[i]));
  }

  cout << mul(res, 1);
}
