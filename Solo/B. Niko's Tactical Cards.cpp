#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> red(n), blue(n);
  for (auto &i : red) {
    cin >> i;
  }
  for (auto &i : blue) {
    cin >> i;
  }
  vector<int> dpB(n, -1e9), dpR(n, -1e9);
  int mx = 0, mn = 0;
  for (int i = 0; i < n; i++) {
    int newMx = max(mx - red[i], blue[i] - mn);
    int newMn = min(mn - red[i], blue[i] - mx);
    mx = newMx;
    mn = newMn;
  }
  cout << mx << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
