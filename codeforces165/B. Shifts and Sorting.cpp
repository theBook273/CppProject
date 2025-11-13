#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int tong = 0, res = 0;
  string s;
  cin >> s;

  for (auto i : s) {
    if (i == '1') {
      tong++;
    } else {
      if (tong != 0) {
        res += tong + 1;
      }
    }
  }

  cout << res << "\n";
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
