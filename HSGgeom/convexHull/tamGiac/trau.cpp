#include <bits/stdc++.h>
#include <cstdio>
#define double long double

using namespace std;

struct Point {
  double x, y;
  bool operator<(const Point &other) {
    if (x != other.x) {
      return x < other.x;
    }
    return y < other.y;
  }
};

vector<Point> point;
double res = 0;
int n;

double cross2(Point a, Point b) { return (a.x * b.y - a.y * b.x); }

double cross3(Point a, Point b, Point c) {
  Point ab;
  ab.x = b.x - a.x;
  ab.y = b.y - a.y;

  Point ac;
  ac.x = c.x - a.x;
  ac.y = c.y - a.y;

  return cross2(ab, ac);
}

void input() {
  point.assign(n, {0, 0});
  for (int i = 0; i < n; i++) {
    cin >> point[i].x >> point[i].y;
  }
}

//=====================================================================//
namespace sub1 {

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        res = max(res, abs(cross3(point[i], point[j], point[k])));
      }
    }
  }
}
} // namespace sub1
//============================namespace sub1===========================//

//=====================================================================//
namespace sub2 {

vector<Point> buildHull() {
  vector<Point> upper, lower;

  sort(point.begin(), point.end());

  for (auto &p : point) {
    while (lower.size() >= 2 &&
           cross3(lower[lower.size() - 2], lower.back(), p) <= 0) {
      lower.pop_back();
    }
    lower.push_back(p);
  }

  for (int i = n - 1; i >= 0; i--) {
    Point p = point[i];
    while (upper.size() >= 2 &&
           cross3(upper[upper.size() - 2], upper.back(), p) <= 0) {
      upper.pop_back();
    }
    upper.push_back(p);
  }

  upper.pop_back();
  lower.pop_back();
  lower.insert(lower.end(), upper.begin(), upper.end());

  return lower;
}

void maxTriagle(vector<Point> hull) {
  int h = hull.size();
  if (h < 3) {
    return;
  }

  for (int i = 0; i < h; i++) {
    int k = (i + 2) % h;
    for (int j = i + 1; j < h; j++) {
      while (!0) {
        double curr = abs(cross3(hull[i], hull[j], hull[k]));
        double next = abs(cross3(hull[i], hull[j], hull[(k + 1) % h]));
        if (next > curr) {
          k = (k + 1) % h;
        } else {
          break;
        }
      }
      res = max(res, abs(cross3(hull[i], hull[j], hull[k])));
    }
  }
}

void solve() {
  vector<Point> hull = buildHull();
  maxTriagle(hull);
}
} // namespace sub2
//============================namespace sub2===========================//

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("test", "r", stdin);
  freopen("testTrau", "w", stdout);

  while (1) {
    cin >> n;
    if (n > 0) {
      res = 0;
      input();
      if (n <= 200) {
        sub1::solve();
      } else {
        sub1::solve();
      }
      cout << fixed << setprecision(2) << res / 2.0 << "\n";
    } else {
      return 0;
    }
  }
}
