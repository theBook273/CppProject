#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

signed main() {
  int n, s;
  cin >> s >> n;
  vector<pair<int, int>> a(n);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }

  sort(a.begin(), a.end(), comp);
  sort(a.begin(), a.end());

  for (auto [i, j] : a) {
    if (s > i) {
      s += j;
    }
  }

  cout << ((s > a.back().first) ? "YES" : "NO");
}
