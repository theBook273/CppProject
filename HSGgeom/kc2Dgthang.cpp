#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;
  Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }

Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }

bool onSegment(Point a, Point b, Point p) {
  return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y &&
         p.y <= max(a.y, b.y);
}

bool segmentsIntersect(Point a, Point b, Point c, Point d) {
  double d1 = cross(b - a, c - a);
  double d2 = cross(b - a, d - a);
  double d3 = cross(d - c, a - c);
  double d4 = cross(d - c, b - c);

  if ((d1 * d2 < 0) && (d3 * d4 < 0))
    return 1;
  if (d1 == 0 && onSegment(a, b, c))
    return 1;
  if (d2 == 0 && onSegment(a, b, d))
    return 1;
  if (d3 == 0 && onSegment(c, d, a))
    return 1;
  if (d4 == 0 && onSegment(c, d, b))
    return 1;

  return 0;
}

double distPointSegment(Point p, Point a, Point b) {
  Point ab = b - a, ap = p - a;
  double len2 = dot(ab, ab);
  double t = dot(ap, ab) / len2;

  if (t < 0.0)
    t = 0.0;
  else if (t > 1.0)
    t = 1.0;

  Point proj(a.x + t * ab.x, a.y + t * ab.y);
  return hypot(p.x - proj.x, p.y - proj.y);
}

double distSegmentSegment(Point a, Point b, Point c, Point d) {
  if (segmentsIntersect(a, b, c, d))
    return 0.0;

  double d1 = distPointSegment(a, c, d);
  double d2 = distPointSegment(b, c, d);
  double d3 = distPointSegment(c, a, b);
  double d4 = distPointSegment(d, a, b);
  return min({d1, d2, d3, d4});
}

int main() {
  Point A, B, C, D;
  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
  cout << fixed << setprecision(6) << distSegmentSegment(A, B, C, D) << "\n";
}
