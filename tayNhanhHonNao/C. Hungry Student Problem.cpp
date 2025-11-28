#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int z;
  cin >> z;
  for (int i = 0; i <= z; i++) {
    int tong = z - (i * 7);
    if (tong >= 0 && tong % 3 == 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
