#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int tong = 0;
  tong += (a / 2) * 2;
  tong += (c / 2) * 2;

  int x = min(b, d);
  tong += x * 2;
  b -= x;
  d -= x;

  a %= 2;
  c %= 2;
  if (a && max(b, d) > 0) {
    tong++;
  }

  if (c && max(b, d) > 0) {
    tong++;
  }

  cout << tong << " ";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pair.inp", "r", stdin);
  freopen("pair.out", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
