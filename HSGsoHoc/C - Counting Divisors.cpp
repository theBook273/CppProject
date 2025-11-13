#include <bits/stdc++.h>

using namespace std;

int cnt(int x) {
  int res = 0;

  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      res++;
      if (x / i != i) {
        res++;
      }
    }
  }

  return res;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    cout << cnt(a) << "\n";
  }
}
