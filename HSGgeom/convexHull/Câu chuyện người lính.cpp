// #include <bits/stdc++.h>
// #define int long long
//
// using namespace std;
//
// struct Point {
//   int x, y;
//   bool operator<(const Point &other) {
//     if (x == other.x) {
//       return y < other.y;
//     }
//     return x < other.x;
//   }
//   bool operator==(const Point &other) { return x == other.x && y == other.y;
//   }
//
//   Point vct(const Point &other) { return {other.x - x, other.y - y}; }
// };
//
// int operator*(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x;
// } int cross3(Point &a, Point &b, Point &c) {
//   Point ab = a.vct(b);
//   Point ac = a.vct(c);
//   return ab * ac;
// }
// vector<Point> point, toRm;
// int n, res = 0, dem;
//
// vector<Point> buildHull() {
//   sort(point.begin(), point.end());
//
//   vector<Point> upper, lower;
//
//   for (int i = 0; i < n; i++) {
//     auto &p = point[i];
//     while (lower.size() >= 2 &&
//            cross3(lower[lower.size() - 2], lower.back(), p) <= 0) {
//       lower.pop_back();
//     }
//     lower.push_back(p);
//   }
//
//   for (int i = n - 1; i >= 0; i--) {
//     auto &p = point[i];
//     while (upper.size() >= 2 &&
//            cross3(upper[upper.size() - 2], upper.back(), p) <= 0) {
//       upper.pop_back();
//     }
//     upper.push_back(p);
//   }
//
//   upper.pop_back();
//   lower.pop_back();
//   lower.insert(lower.end(), upper.begin(), upper.end());
//
//   return lower;
// }
//
// void rm() {
//   unordered_set<long long> S;
//   S.reserve(toRm.size() * 2);
//
//   for (auto &p : toRm) {
//     long long code = ((long long)p.x << 32) ^ p.y;
//     S.insert(code);
//   }
//
//   vector<Point> newP;
//   newP.reserve(point.size());
//
//   for (auto &p : point) {
//     long long code = ((long long)p.x << 32) ^ p.y;
//     if (!S.count(code)) {
//       newP.push_back(p);
//     }
//   }
//
//   point.swap(newP);
//   n = point.size();
// }
//
// signed main() {
//   cin.tie()->sync_with_stdio(0);
//   cin >> n;
//   dem = n;
//   point.resize(n);
//   for (auto &[x, y] : point) {
//     cin >> x >> y;
//   }
//
//   while (!point.empty()) {
//     toRm = buildHull();
//     if (!toRm.empty()) {
//       res++;
//       rm();
//     }
//   }
//   cout << res << "\n";
// }
//
#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
  int id; // lưu index gốc
  bool operator<(const Point &o) const {
    if (x != o.x)
      return x < o.x;
    return y < o.y;
  }
};

int cross(const Point &a, const Point &b, const Point &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<int> monotoneHull(const vector<Point> &pts, const vector<bool> &alive) {
  vector<Point> lower, upper;
  vector<int> hull;

  // Build lower
  for (auto &p : pts) {
    if (!alive[p.id])
      continue;
    while (lower.size() >= 2 &&
           cross(lower[lower.size() - 2], lower.back(), p) <= 0)
      lower.pop_back();
    lower.push_back(p);
  }

  // Build upper
  for (int i = (int)pts.size() - 1; i >= 0; i--) {
    auto &p = pts[i];
    if (!alive[p.id])
      continue;
    while (upper.size() >= 2 &&
           cross(upper[upper.size() - 2], upper.back(), p) <= 0)
      upper.pop_back();
    upper.push_back(p);
  }

  // Combine lower and upper
  if (!lower.empty())
    lower.pop_back();
  if (!upper.empty())
    upper.pop_back();
  for (auto &p : lower)
    hull.push_back(p.id);
  for (auto &p : upper)
    hull.push_back(p.id);
  return hull;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Point> pts(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
    pts[i].id = i;
  }

  sort(pts.begin(), pts.end()); // sort 1 lần

  vector<bool> alive(n, true);
  int res = 0;

  while (true) {
    int aliveCount = count(alive.begin(), alive.end(), true);
    if (aliveCount < 3)
      break; // còn <3 điểm → stop

    vector<int> hull = monotoneHull(pts, alive);
    if (hull.empty())
      break;

    for (int id : hull)
      alive[id] = false;
    res++;
  }

  cout << res << "\n";
}
