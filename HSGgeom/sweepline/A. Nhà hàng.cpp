#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, int>> events;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int u, v, i = 0; i < n; i++) {
    cin >> u >> v;
    events.push_back({u, 1});
    events.push_back({v + 1, -1});
  }

  sort(events.begin(), events.end());

  int curr, ans;
  curr = ans = 0;
  for (auto &[time, val] : events) {
    curr += val;
    ans = max(ans, curr);
  }

  cout << ans << "\n";
}
