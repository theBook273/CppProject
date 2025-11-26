#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, q;

namespace sub1 {

void solve() {
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
} // namespace sub1

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("rating.inp", "r", stdin);
  freopen("rating.out", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    if (n <= 5000) {
      sub1::solve();
    } else {
    }
  }
}
