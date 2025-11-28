#include <bits/stdc++.h>

using namespace std;

string model;
char x, y;

bool great(string a, string b) {
  if (a.size() > b.size()) {
    return 1;
  } else if (a.size() < b.size()) {
    return 0;
  }
  for (int i = 0; i < a.size(); i++) {
    if (a[i] > b[i]) {
      return 1;
    }
    if (a[i] < b[i]) {
      return 0;
    }
  }
  return 1;
}

namespace sub1 {

int demx = 0, demy = 0;
int n;
vector<string> store;
string s;

void gen() {
  if (s.size() == n) {
    store.push_back(s);
    return;
  }
  if (!(s.empty() && x == '0')) {
    if (demx < n / 2) {
      demx++;
      s.push_back(x);
      gen();
      demx--;
      s.pop_back();
    }
  }
  if (!(s.empty() && y == '0')) {
    if (demy < n / 2) {
      demy++;
      s.push_back(y);
      gen();
      demy--;
      s.pop_back();
    }
  }
}

void solve() {
  s.clear();
  store.clear();
  n = model.size();

  if (y < model[0]) {
    n++;
  }

  if (n % 2 == 1) {
    n++;
  }

  gen();
  sort(store.begin(), store.end());

  for (auto i : store) {
    if (great(i, model)) {
      cout << i << "\n";
      return;
    }
  }

  n += 2;
  store.clear();
  gen();
  sort(store.begin(), store.end());
  for (auto i : store) {
    if (great(i, model)) {
      cout << i << "\n";
      return;
    }
  }
}

} // namespace sub1

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("digits.inp", "r", stdin);
  freopen("digits.out", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    cin >> model >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    sub1::solve();
  }
}
