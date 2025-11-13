#include <bits/stdc++.h>
#define int long long

using namespace std;

bool primeCheck(int n) {
  if (n < 2) {
    return 0;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

void solve() {
  int n, k;
  cin >> n >> k;
  if (n == 1 && k == 2) {
    cout << "YES\n";
  } else if (k == 1) {
    cout << ((primeCheck(n)) ? "YES\n" : "NO\n");
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
