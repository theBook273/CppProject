#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

int cnt(int x, int k, int r) {
  if (x < r) {
    return 0;
  }
  int base = (x / k);
  int extra = 0;
  if (r != 0 && x % k >= r) {
    extra++;
  }
  return base + extra;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;

  int ans = 0;
  for (int r = 0; r < k; r++) {
    int cnt1 = cnt(n, k, r);
    int need = (k - r) % k;
    int cnt2 = cnt(m, k, need);
    ans += cnt1 * cnt2;
  }

  cout << ans;
}
