#include <bits/stdc++.h>

using namespace std;

void solve() {}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, k, res = 0;
  int t;
  cin >> t;
  while (t--) {
    res = 0;
    cin >> n >> k;
    vector<vector<int>> mp(k);

    for (int temp, i = 0; i < n; ++i) {
      cin >> temp;
      mp[i % k].push_back(temp);
    }

    for (int i = 0; i < k; ++i) {
      int maxn = 1, cur = 1;
      auto &g = mp[i];
      sort(g.begin(), g.end());
      for (int j = 0; j < g.size(); j++) {
        if (g[j] == g[j - 1]) {
          cur++;
        } else {
          cur = 1;
        }
        maxn = max(maxn, cur);
      }
      res += g.size() - maxn;
    }
    cout << res << "\n";
  }
}
