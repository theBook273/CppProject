#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> mp;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, k, res = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    int temp = k + a[i];
    if (mp.count(temp)) {
      for (auto x : mp[temp]) {
        if (x > i) {
          res++;
        }
      }
    }
  }
  cout << res;
}
