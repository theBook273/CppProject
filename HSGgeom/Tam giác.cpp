#include <bits/stdc++.h>

using namespace std;

struct Point {
  double x, y;
};

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

double S(Point a, Point b, Point c) {
  Point AB = {b.x - a.x, b.y - a.y};
  Point AC = {c.x - a.x, c.y - a.y};
  return abs(cross(AB, AC) / 2.0);
}

Point operator-(Point a, Point b) { return {b.x - a.x, b.y - a.y}; }

Point a[1005];

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  double tong = 0;

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++)
        tong += fabs(cross(a[j] - a[i], a[k] - a[i])) / 2;

  cout << fixed << setprecision(1) << tong;
}
