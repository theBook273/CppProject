#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int binPow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res % MOD;
}

void solve() {
  int n, k;
  cin >> n >> k;
  cout << binPow(n, k) << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
