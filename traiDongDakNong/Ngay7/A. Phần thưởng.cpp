#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("quyhoachdong.inp", "r", stdin);
  freopen("quyhoachdong.out", "w", stdout);

  int a, b, c, m;
  while (cin >> a >> b >> c >> m) {
    if (a + b + c >= m && a * b * c != 0 && m >= 3) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
  }
}
