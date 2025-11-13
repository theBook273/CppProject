#include <bits/stdc++.h>

using namespace std;

struct point {
  double x, y;
};

signed main() {
  int n;
  cin >> n;
  point a[n];
  for (auto &i : a) {
    cin >> i.x >> i.y;
  }

  double res = 0;
  for (int i = 0; i < n; i++) {
    res += (a[i % n].x - a[(i + 1) % n].x) * (a[i % n].y + a[(i + 1) % n].y);
  }

  cout << fixed << setprecision(9) << abs(res / 2.0);
}
