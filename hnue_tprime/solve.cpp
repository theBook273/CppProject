#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

namespace ngu {
bool prime(int x) {
  if (x < 2) {
    return false;
  }
  if (x == 2 || x == 3 || x == 5) {
    return true;
  }
  for (int i = 2; i < n; i++) {
    if (x % i == 0)
      return false;
  }
  return true;
}
void solve() {
  int res;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    if (i * i > n) {
      break;
    } else {
      if (prime(i) && i * i <= n) {
        res++;
      }
    }
  }
  cout << res;
}
} // namespace ngu

namespace sub1 {
void solve() {
  vector<bool> isPrime(1e6 + 1, true);
  vector<int> prime;
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= 1e6; i++) {
    if (isPrime[i]) {
      prime.push_back(i);
      for (int j = i * i; j <= 1e6; j += i) {
        isPrime[j] = false;
      }
    }
  }

  int res = 0;
  for (auto &i : prime) {
    if (i * i <= n) {
      res++;
    }
    if (i > n) {
      break;
    }
  }
  cout << res;
}
} // namespace sub1

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  freopen("TPRIME.INP", "r", stdin);
  freopen("TPRIME.OUT", "w", stdout);

  cin >> n;
  sub1::solve();
}
