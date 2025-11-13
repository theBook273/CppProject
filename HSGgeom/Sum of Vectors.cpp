#include <bits/stdc++.h>

using namespace std;

struct Point {
  double x, y;

  Point operator+(const Point &other) const {
    return {x + other.x, y + other.y};
  }

  bool operator<(const Point &other) const {
    if (x == other.x) {
      return y < other.y;
    }
    return x < other.x;
  }
};

vector<Point> a;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  double x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a.push_back({x, y});
  }

  sort(a.begin(), a.end());
  for (auto [x, y] : a) {
    cout << x << " " << y << "\n";
  }
}
