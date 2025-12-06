#include <bits/stdc++.h>

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

Line from2Point(Point a, Point b) {
  Line res;
  Point vtcp = {b.x - a.x, b.y - a.y};
  Point vtpt = {vtcp.y / vtcp.x, -1};
  res = {vtpt.x, vtpt.y, vtpt.x * -a.x + vtpt.y * -a.y};
  return res;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  Point poA, poB, poC;
  cin >> poA.x >> poA.y;
  cin >> poB.x >> poB.y;
  cin >> poC.x >> poC.y;
  Line line = from2Point(poB, poC);
  cout << fixed << setprecision(9) << dis(poA, line);
}
