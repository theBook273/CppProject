#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  vector<int> dem(1e5 + 1, 0);

  int n;
  cin >> n;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    dem[temp]++;
  }

  int res = 1;

  for (int i = 1e5; i >= 1; i--) {
    if (dem[i] >= 4 && res == 1) {
      cout << i * i << "\n";
      return;
    } else if (dem[i] >= 2) {
      res *= i;
      if (res != i) {
        cout << res << "\n";
        return;
      }
    }
  }

  cout << -1 << "\n";
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
