#include <bits/stdc++.h>

using namespace std;

vector<int> p[1009];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 1; i <= 1000; i++) {
    for (int j = i; j <= 1000; j++) {
      if (__gcd(i, j) == 1) {
        p[i].push_back(j);
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    vector<int> mark(1009, 0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int temp;
      cin >> temp;
      mark[temp] = i;
    }
    int ans = -1;
    for (int i = 1; i <= 1000; i++) {
      if (mark[i] != 0) {
        for (auto j : p[i]) {
          if (mark[j] != 0) {
            ans = max(ans, mark[i] + mark[j]);
          }
        }
      }
    }
    cout << ans << "\n";
  }
}
