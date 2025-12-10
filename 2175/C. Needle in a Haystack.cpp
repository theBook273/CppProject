#include <bits/stdc++.h>

using namespace std;

bool preferA(int x, int y, string &a, string &b) {
  while (a[x] == b[y] && x < (int)a.size() && y < (int)b.size()) {
    ++x;
    ++y;
  }

  if (x == (int)a.size() || y == (int)b.size()) {
    return 1;
  }

  if (a[x] < b[y]) {
    return 1;
  } else if (a[x] > b[y]) {
    return 0;
  } else {
    return 1;
  }
}

signed solve() {
  string a, b;
  cin >> a >> b;
  unordered_map<char, int> cnt1, cnt2;

  for (auto &i : a) {
    cnt1[i]++;
  }

  for (auto &i : b) {
    cnt2[i]++;
  }

  for (auto [i, j] : cnt1) {
    if (cnt2[i] < j) {
      cout << "Impossible\n";
      return 0;
    }
  }

  vector<int> wall(a.size() + 1, 0);
  int matemp = a[0];

  for (int i = 0; i < (int)a.size() - 1; i++) {
    if (a[i + 1] > matemp) {
      wall[i] = 1;
      matemp = a[i + 1];
    }
  }

  string ex;

  for (auto &[c, dem] : cnt2) {
    dem -= cnt1[c];
    for (int i = 0; i < dem; i++) {
      ex.push_back(c);
    }
  }

  sort(ex.begin(), ex.end());

  int id1, id2;
  id1 = id2 = 0;

  string res;

  while (id1 < (int)a.size() && id2 < (int)ex.size()) {
    if (a[id1] > ex[id2]) {
      res.push_back(ex[id2]);
      ++id2;
    } else if (a[id1] < ex[id2]) {
      res.push_back(a[id1]);
      ++id1;
    } else {
      if (preferA(id1, id2, a, ex)) {
        res.push_back(a[id1]);
        ++id1;
      } else {
        res.push_back(ex[id2]);
        ++id2;
      }
    }
  }

  while (id2 < (int)ex.size()) {
    res.push_back(ex[id2]);
    ++id2;
  }

  while (id1 < (int)a.size()) {
    res.push_back(a[id1]);
    ++id1;
  }

  cout << res << "\n";

  return 0;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
