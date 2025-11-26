#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int x, l, r;
    cin >> x >> l >> r;
    for (int i = l; i <= r; i++) {
      x = abs(x - a[i]);
    }
    cout << x << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("rating.inp", "r", stdin);
  freopen("rating.out", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
