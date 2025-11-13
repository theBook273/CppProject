#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> inShort(vector<int> a) {
  vector<pair<int, int>> res;

  map<int, int> mp;
  for (auto i : a) {
    mp[i]++;
  }
  for (auto [i, j] : mp) {
    res.push_back({i, j});
  }

  return res;
}

pair<int, int> phanSo(int a, int b) {
  int x = __gcd(a, b);
  return {a / x, b / x};
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &i : a) {
    cin >> i;
  }

  for (auto &i : b) {
    cin >> i;
  }

  vector<pair<int, int>> shortA, shortB;
  shortA = inShort(a);
  shortB = inShort(b);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
