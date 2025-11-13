#include <bits/stdc++.h>

using namespace std;

signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int l = 0, tong = 0;
  pair<int, pair<int, int>> res = {0, {0, 0}};
  deque<int> q;
  for (int r = 0; r < n; r++) {
    tong += a[r];
    if (r - l + 1 == k) {
      if (res.first < tong) {
        res.first = tong;
        res.second.first = l;
        res.second.second = r;
      }
      tong -= a[l];
      l++;
    }
  }
  cout << res.first << "\n";
  for (int i = res.second.first; i <= res.second.second; i++) {
    cout << a[i] << " ";
  }
}
