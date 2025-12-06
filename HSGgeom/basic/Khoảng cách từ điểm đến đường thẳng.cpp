#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

struct Point {
  double x, y;
};

struct Line {
  double a, b, c;
};

double dis(Point a, Line b) {
  return abs(a.x * b.a + a.y * b.b + b.c) / sqrt((b.a * b.a) + (b.b * b.b));
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  Point point;
  Line line;

  cin >> point.x >> point.y >> line.a >> line.b >> line.c;
  cout << fixed << setprecision(9) << dis(point, line);
}
