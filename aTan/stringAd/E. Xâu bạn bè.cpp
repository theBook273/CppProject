#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> x(n);
  set<char> se[n + 1];
  for (auto &i : x) {
    cin >> i;
  }

  for (auto &i : x) {
    for (auto &j : i) {
      j = tolower(j);
    }
  }

  for (int i = 0; i < n; i++) {
    for (char &a : x[i]) {
      se[i].insert(a);
    }
  }

  for (int i = 0; i < n - 1; i++) {
    if (se[i] != se[i + 1]) {
      cout << 0;
      return 0;
    }
  }

  cout << 1;
}
