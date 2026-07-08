#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double a, b;
  cin >> a >> b;

  cout << fixed << setprecision(6) << ((a * a) + (b * b)) / 2 << "\n";
  cout << fixed << setprecision(6) << (abs(a) + abs(b)) / 2;
}
