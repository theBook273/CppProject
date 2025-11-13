#include <bits/stdc++.h>

using namespace std;

string ans[] = {"NO\n", "YES\n"};

bool check(int n, int m) {
  if (n == m) {
    return 1;
  }

  if (n % 3 == 0) {
    return check(n * 2 / 3, m) || check(n * 1 / 3, m);
  }

  return 0;
}

void solve() {
  int n, m;
  cin >> n >> m;

  cout << ans[check(n, m)];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
