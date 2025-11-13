#include <bits/stdc++.h>
#define int long long

using namespace std;
vector<pair<int, int>> a;

bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first)
    return a.second > b.second;
  return a.first < b.first;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int l, r, i = 0; i < n; i++) {
    cin >> l >> r;
    a.push_back({l, 1});
    a.push_back({r, -1});
  }

  sort(a.begin(), a.end(), comp);

  int cur = 0, ans = 0;
  for (auto [i, j] : a) {
    cur += j;
    ans = max(ans, cur);
  }
  cout << ans;
}
