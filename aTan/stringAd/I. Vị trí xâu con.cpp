#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &s : a) {
    cin >> s;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && a[i].size() <= a[j].size()) {
        int flag = 0;
        for (int x = 0; x <= (int)(a[j].size() - a[i].size()); x++) {
          string temp = a[j].substr(x, a[i].size());
          if (temp == a[i]) {
            cout << i + 1 << " ";
            flag = 1;
            break;
          }
        }
        if (flag) {
          break;
        }
      }
    }
  }
}
