#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<string> a(n);
  vector<int> dem(n, 0);
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      if (a[i].find(a[j]) != -1) {
        dem[i]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dem[i] << "\n";
  }
}
