#include <bits/stdc++.h>

using namespace std;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.second > b.second;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<pair<int, int>, int>> a(n);
  for (auto &i : a) {
    cin >> i.first.first >> i.first.second >> i.second;
  }
  sort(a.begin(), a.end(), comp);
  sort(a.begin(), a.end());
  // for (auto [i, c] : a) {
  //   auto [a, b] = i;
  //   cout << a << " " << b << " " << c << "\n";
  // }
  // cout << "\n";
  for (auto [i, real] : a) {
    auto [l, r] = i;
    if (l <= k && k <= r && real >= k) {
      k = real;
    }
  }
  cout << k << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
