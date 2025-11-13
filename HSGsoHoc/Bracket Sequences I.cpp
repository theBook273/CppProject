#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long modpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n % 2 == 1) {
    cout << 0;
    return 0;
  }

  int k = n / 2;
  vector<long long> fact(2 * k + 1);
  fact[0] = 1;
  for (int i = 1; i <= 2 * k; i++)
    fact[i] = fact[i - 1] * i % MOD;

  long long inv_fact_k = modpow(fact[k], MOD - 2);
  long long C = fact[2 * k] * inv_fact_k % MOD * inv_fact_k % MOD;
  long long ans = C * modpow(k + 1, MOD - 2) % MOD;
  cout << ans;
}
