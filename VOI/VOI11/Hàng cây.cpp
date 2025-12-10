#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;
const int MOD = 1e9;

int n, h;

vector<int> calPrime(int x) {
  vector<bool> isPrime(x + 1, 1);
  vector<int> prime;

  for (int i = 2; i <= x; i++) {
    if (isPrime[i]) {
      prime.push_back(i);
      for (int j = i * i; j <= x; j += i) {
        isPrime[j] = 0;
      }
    }
  }

  return prime;
}

int countP(int n, int p) {
  int c = 0;
  while (n) {
    n /= p;
    c += n;
  }
  return c;
}

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

int cata(int n) {
  vector<int> prime = calPrime(2 * n);
  int res = 1;

  for (int p : prime) {
    int cnt = countP(2 * n, p) - 2LL * countP(n, p);

    int x = n + 1;
    while (x % p == 0) {
      cnt--;
      x /= p;
    }

    if (cnt > 0) {
      res = mul(res, binPow(p, cnt));
    }
  }

  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> h;

  vector<int> a(n, 0);
  for (auto &i : a) {
    cin >> i;
  }

  int res1 = 2;
  int mini = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > mini) {
      break;
    }
    res1++;
    mini = min(mini, a[i]);
  }

  cout << res1 << "\n";

  n++;
  cout << cata(n);
}
