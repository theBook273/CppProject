#include <bits/stdc++.h>
#include <variant>
#include <vector>

using namespace std;

const int N = 2e5;
const int MOD = 1e9 + 7;

int a[N + 5], dp[N + 5], lastSum[N + 5], spf[N + 5];

int add(int x, int y) { return ((x % MOD) + (y % MOD)) % MOD; }
int sub(int x, int y) { return (x - y + MOD) % MOD; }

void sieve() {
  iota(spf, spf + N, 0);
  for (int i = 2; i * i < N; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < N; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}

vector<int> getPrime(int n) {
  vector<int> factors;
  if (n == 1) {
    return factors;
  }
  while (n != 1) {
    int p = spf[n];
    factors.push_back(p);
    while (n > 1 && n % p == 0) {
      n /= p;
    }
  }
  return factors;
}

vector<int> getAllDiv(int n) {
  vector<int> div;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      div.push_back(i);
      if (i * i != n) {
        div.push_back(n / i);
      }
    }
  }
  return div;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sieve();

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  dp[0] = 1;
  vector<int> divA = getAllDiv(a[0]);
  for (auto d : divA) {
    lastSum[d] = add(lastSum[d], dp[0]);
  }

  for (int i = 1; i < n; i++) {
    vector<int> pFact = getPrime(a[i]);
    int k = pFact.size();
    int cur = 0;

    for (int j = 1; j < (1 << k); j++) {
      int d = 1;
      int setBits = 0;
      for (int bit = 0; bit < k; bit++) {
        ii
      }
    }
  }
}
