#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i += 2) {
    cout << i << " ";
  }

  if (n & 1) {
    n--;
  }

  for (int i = n; i >= 2; i -= 2) {
    cout << i << " ";
  }

  cout << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
