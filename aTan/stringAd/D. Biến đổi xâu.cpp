#include <bits/stdc++.h>

using namespace std;

bool aTob(string a, string b) {
  vector<int> pos;
  set<char> se;
  for (auto i : b) {
    se.insert(i);
  }
  if (se.size() == 1) {
    return 1;
  }
  se.clear();
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] != b[i]) {
      pos.push_back(i);
      se.insert(b[i]);
    }
  }
  if (se.size() == 1) {
    for (int i = 0; i < (int)pos.size() - 1; i++) {
      if (pos[i] + 1 != pos[i + 1]) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

void solve() {
  string a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << "\n";
    return;
  }
  if (aTob(a, b)) {
    cout << 1 << "\n";
    return;
  }
  swap(a, b);
  if (aTob(a, b)) {
    cout << 1 << "\n";
    return;
  }
  cout << 2 << "\n";
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
