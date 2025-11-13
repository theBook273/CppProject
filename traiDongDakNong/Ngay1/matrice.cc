#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 9;

int n, m, t, res = 0;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m >> t;
  if (n > m) {
    swap(n, m);
  }

  if (m % 2 == 1) {
    int dis = m / 2;
    for (int i = dis; i <= t - dis; i++) {
      // cout << i << " " << min(i - dis + 1, t - (i + dis) + 1) << "\n";
      res = (res + min(i - dis + 1, t - (i + dis) + 1)) % MOD;
    }
  } else {
    if (n == 1) {
      for (int i = 0; i <= t; i++) {
        for (int d = 1; d <= t; d++) {
          if (i + d * (m - 1) <= t) {
            res = (res + 1) % MOD;
          }
        }
      }
    }
  }

  cout << res << "\n";
}
