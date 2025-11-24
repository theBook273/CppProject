#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  vector<pair<int, int>> location;
  int n, m, c;
  cin >> c >> m >> n;
  for (int pos, i = 0; i < m; i++) {
    cin >> pos;
    location.push_back({pos, +1});
  }
  for (int pos, need, i = 0; i < n; i++) {
    cin >> pos >> need;
    location.push_back({pos, -need});
  }
  int truck = c;
  int shipped = 0;
  sort(location.begin(), location.end());
  for (auto &[pos, need] : location) {
    if (need > 0) {
      truck = c;
    } else {
      if (truck + need >= 0) {
        truck += need;
        shipped -= need;
      }
    }
  }
  cout << shipped << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("pepsi.inp", "r", stdin);
  freopen("pepsi.out", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
