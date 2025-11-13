#include <bits/stdc++.h>
#define long long long long
using namespace std;

long long n, a[17][17], dis[1 << 17][17];

main() {
  cin >> n;

  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (long long mask = 1; mask < (long long)pow(2, n); mask++) {
    if (__builtin_popcount(mask) == 1)
      continue;
    else
      for (long long i = 0; i < n; i++) {
        if ((mask >> i) & 1 == 1) {
          dis[mask][i] = 1e9;
          long long temp = mask ^ (1 << i);
          for (long long j = 0; j < n; j++) {
            if (((temp >> j) & 1) == 1) {
              dis[mask][i] = min(dis[mask][i], dis[temp][j] + a[j][i]);
            }
          }
        }
      }
  }
  long long ans = 1e9;
  for (long long i = 0; i < n; i++) {
    ans = min(ans, dis[(1 << n) - 1][i]);
  }
  cout << ans;
}
