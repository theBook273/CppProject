#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n, k, tong = 0, ans = 0, f = 0;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }

  vector<pair<int, int>> items;
  for (int i = 0; i < n; i++) {
    items.push_back({b[i], a[i]});
  }
  sort(items.begin(), items.end(), greater<>());

  for (int i = 0; i < n; i++) {
    tong += max(0LL, items[i].first - items[i].second);
  }

  priority_queue<int> q;
  if (k == 0) {
    ans = max(ans, tong);
  }
  for (auto i : items) {
    tong -= max(0LL, i.first - i.second);
    q.push(i.second);
    f += i.second;
    if (q.size() > k) {
      f -= q.top();
      q.pop();
    }
    if (q.size() == k) {
      ans = max(ans, tong - f);
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
