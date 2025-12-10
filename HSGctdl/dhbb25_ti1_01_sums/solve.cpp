#include <bits/stdc++.h>
#define int long long

using namespace std;

map<int, vector<int>> ways;
vector<int> a;
set<vector<int>> se;
int n;

vector<int> process(int x) {
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if ((x >> i) & 1) {
      res.push_back(a[i]);
    }
  }

  sort(res.begin(), res.end());
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  a.resize(n, 0);
  for (auto &i : a) {
    cin >> i;
  }

  int full = (1 << n);
  for (int mask = 1; mask < full; mask++) {
    vector<int> pos;
    int tong = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }
    for (auto i : pos) {
      tong += a[i];
    }
    ways[tong].push_back(mask);
  }

  cout << ways.size() << "\n";

  pair<int, vector<int>> num = {0, {}};

  for (auto &[i, j] : ways) {
    if (j.size() >= num.second.size()) {
      num = {i, j};
    }
  }

  cout << num.first << " " << num.second.size() << "\n";

  for (auto &i : num.second) {
    se.insert(process(i));
  }

  for (auto i : se) {
    for (auto x : i) {
      cout << x << " ";
    }
    break;
  }
}
