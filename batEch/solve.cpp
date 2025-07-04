#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, int> opa;
  for (int &i : a) {
    cin >> i;
    if (i <= n)
      opa[i]++;
  }
  vector<int> mp(n + 1, 0);
  for (auto [start, cnt] : opa) {
    for (int i = start; i <= n; i += start) {
      mp[i] += cnt;
    }
  }

  int res = 0;

  for (int i = 1; i <= n; ++i) {
    res = max(res, mp[i]);
  }

  cout << res << "\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
