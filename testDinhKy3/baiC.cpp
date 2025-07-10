#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = a[i] + a[j];
      auto tar = lower_bound(a.begin() + j + 1, a.end(), temp);
      if (tar != a.begin() + j + 1) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}
