#include <bits/stdc++.h>

using namespace std;

struct Point {
  double x, y;
};

struct Line {
  double a, b, c;
};

double disPoToLine(Point a, Line b) {
  return abs(a.x * b.a + a.y * b.b + b.c) / sqrt((b.a * b.a) + (b.b * b.b));
}

double disOfVec(Point a) { return (sqrt(a.x * a.x + a.y * a.y)); }

double dot(Point a, Point b) { return (a.x * b.x + a.y * b.y); }

Point vecFrom2point(Point a, Point b) { return {b.x - a.x, b.y - a.y}; }

Line from2Point(Point a, Point b) {
  Line res;
  Point vtcp = vecFrom2point(a, b);
  Point vtpt = {vtcp.y / vtcp.x, -1};
  res = {vtpt.x, vtpt.y, vtpt.x * -a.x + vtpt.y * -a.y};
  return res;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  Point poA, poB;
  Line line;
  cin >> poA.x >> poA.y;
  cin >> poB.x >> poB.y;
  cin >> line.a >> line.b >> line.c;

  double temp1 = poA.x * line.a + poA.y * line.b + line.c;
  double temp2 = poB.x * line.a + poB.y * line.b + line.c;

  cout << ((temp1 * temp2 > 0) ? "YES" : "NO");
}
