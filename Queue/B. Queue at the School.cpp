#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, t;
  cin >> n >> t;
  vector<char> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  while (t--) {
    vector<int> mark;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == 'B' && a[i + 1] == 'G') {
        mark.push_back(i);
      }
    }
    for (auto i : mark) {
      swap(a[i], a[i + 1]);
    }
  }
  for (auto i : a) {
    cout << i;
  }
}
