#include <bits/stdc++.h>

using namespace std;

struct point {
  double x, y;
};

double operator*(point a, point b) { return a.x * b.x + a.y * b.y; }

double len(point a) { return (sqrt(a.x * a.x + a.y * a.y)); }

signed main() {
  point a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  cout << fixed << setprecision(9) << (acos((a * b) / (len(a) * len(b))));
}
