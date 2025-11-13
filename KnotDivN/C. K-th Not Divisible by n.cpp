#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int l = 1, r = 1e9, m;

  while (l <= r) {
    m = (l + r) / 2;
    // cout << m << "\n";
    if (m * (n - 1) >= k) {
      if ((m - 1) * (n - 1) < k) {
        break;
      }
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  int startOfBlock = (m - 1) * n + 1;
  int idOfStart = (m - 1) * (n - 1) + 1;

  while (idOfStart != k) {
    idOfStart++;
    startOfBlock++;
  }
  cout << startOfBlock << "\n";
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
