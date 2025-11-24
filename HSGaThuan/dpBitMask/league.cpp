#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  unordered_map<int, int> dp, conflict;
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    int mask = 0;
    mask |= 1 << v;
    conflict[u] |= mask;
    mask = 0;
    mask |= 1 << u;
    conflict[v] |= mask;
  }

  for (int i = 0; i < n; i++) {
    dp[(1 << i)] = a[i];
  }

  int full = (1 << n) - 1;
  for (int mask = 0; mask <= full; mask++) {
    for (int i = 0; i < n; i++) {
      if ((mask & conflict[i]) == 0 && !(mask & (1 << i)) && dp.count(mask)) {
        int newmask = mask | (1 << i);
        dp[newmask] = max(dp[newmask], dp[mask] + a[i]);
      }
    }
  }

  int ans = 0;
  for (auto &[x, i] : dp) {
    ans = max(ans, i);
  }
  cout << ans;
}
