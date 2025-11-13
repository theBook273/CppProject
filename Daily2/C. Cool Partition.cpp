#include <bits/stdc++.h>

using namespace std;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> dem;
    for (auto &i : a) {
      cin >> i;
      dem[i]++;
    }

    int tong = 0;
    map<int, int> check;

    for (int i = n - 1; i >= 0; i--) {
      check[a[i]]++;

      if (check.size() == dem.size()) {
        for (auto j : check) {
          dem[j.first] -= j.second;
          if (dem[j.first] == 0) {
            dem.erase(j.first);
          }
        }
        tong++;
        check.clear();
      }
    }

    cout << tong + (!dem.empty()) << "\n";
  }
}
