#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

int base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
int mod_mul(int a, int b, int mod) {
  return ((__int128)a % mod * b % mod) % mod;
}

int binpow(int a, int n, int modu) {
  int res = 1;
  a %= modu;
  while (n != 0) {
    if (n % 2 != 0) {
      res = mod_mul(res, a, modu);
    }
    n /= 2;
    a = mod_mul(a, a, modu);
  }
  return res;
}

bool check(int n) {
  if (n < 2) {
    return 0;
  } else if (n == 2 || n == 3) {
    return 1;
  } else if (n % 2 == 0 || n % 3 == 0) {
    return 0;
  }

  int d = n - 1;
  int s = 0;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }

  for (auto a : base) {
    if (a >= n) {
      continue;
    }
    int x = binpow(a, d, n) % n;
    if (x == 1 || x == n - 1) {
      continue;
    }

    bool check = 0;

    for (int i = 1; i <= s - 1; ++i) {
      x = binpow(x, 2, n);
      if (x == n - 1) {
        check = 1;
        break;
      }
    }

    if (!check) {
      return 0;
    }
  }

  return 1;
}

void solve() {
  int n, m;
  cin >> n >> m;

  if ((check(n) && m == 1) || (n == 1 && m == 2)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
