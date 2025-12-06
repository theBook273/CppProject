#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<pair<int, int>> guest;

bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int l, r, i = 0; i < n; i++) {
    cin >> l >> r;
    guest.push_back({l, +1});
    guest.push_back({r + 1, -1});
  }

  sort(guest.begin(), guest.end(), comp);

  int sum = 0, res = 0;

  for (auto [i, j] : guest) {
    sum += j;
    res = max(sum, res);
  }

  cout << res;
}
