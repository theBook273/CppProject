#include <bits/stdc++.h>

using namespace std;

struct Point {
  double x, y;
};

double SofPoly(vector<Point> &poly) {
  double res = 0;
  int n = poly.size();
  for (int i = 0; i < n; i++) {
    res += (poly[i % n].x - poly[(i + 1) % n].x) *
           (poly[i % n].y + poly[(i + 1) % n].y);
  }
  return abs(res / 2.0);
}

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

double S(Point a, Point b, Point c) {
  Point AB = {b.x - a.x, b.y - a.y};
  Point AC = {c.x - a.x, c.y - a.y};
  return abs(cross(AB, AC) / 2.0);
}

bool inSide(Point x, vector<Point> &poly) {
  double tong = 0;
  double chuan = SofPoly(poly);

  int n = poly.size();
  for (int i = 0; i < n; i++) {
    tong += (S(x, poly[i % n], poly[(i + 1) % n]));
  }

  return (tong == chuan);
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Point> coc(n);
  for (int i = 0; i < n; i++) {
    cin >> coc[i].x >> coc[i].y;
  }

  int m;
  cin >> m;
  vector<Point> carrot(m);
  for (int i = 0; i < m; i++) {
    cin >> carrot[i].x >> carrot[i].y;
  }

  int q;
  cin >> q;
  while (q--) {
    int temp;
    cin >> temp;
    vector<Point> place;
    for (int u, i = 0; i < temp; i++) {
      cin >> u;
      place.push_back(coc[u - 1]);
    }
    int tong = 0;
    for (auto x : carrot) {
      tong += inSide(x, place);
    }
    cout << tong << "\n";
  }
}
