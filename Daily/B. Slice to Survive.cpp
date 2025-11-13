#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int m, n, x, y;
  cin >> n >> m >> x >> y;

  vector<pair<int, int>> rec = {{x, m}, {n - x + 1, m}, {n, y}, {n, m - y + 1}};

  int ans = m + n;
  for (auto [r, c] : rec) {
    int res = 0;
    while (r > 1) {
      ++res;
      r = (r + 1) / 2;
    }
    while (c > 1) {
      ++res;
      c = (c + 1) / 2;
    }
    ans = min(ans, res);
  }

  cout << 1 + ans << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
