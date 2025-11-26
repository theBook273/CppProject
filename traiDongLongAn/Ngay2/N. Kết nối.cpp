#include <bits/stdc++.h>
#include <iomanip>
#define double long double

using namespace std;

struct Edge {
  int from, to;
  double len;
  bool operator<(const Edge &other) { return len < other.len; }
};

struct Point {
  double x, y;
  double dis(const Point &other) {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
  }
};

int n;
double w, c;
vector<Point> point;
vector<Edge> edge1, edge2;
vector<int> dsu;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
bool join(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a != b) {
    dsu[a] = b;
    return 1;
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  point.resize(n + 1);
  dsu.resize(n + 1);
  iota(dsu.begin(), dsu.end(), 0);
  for (int i = 1; i <= n; i++) {
    cin >> point[i].x >> point[i].y;
  }

  cin >> w >> c;

  for (int i = 1; i <= n; i++) {
    edge1.push_back({0, i, w});
    for (int j = i + 1; j <= n; j++) {
      edge1.push_back({i, j, c * point[i].dis(point[j])});
      edge2.push_back({i, j, c * point[i].dis(point[j])});
    }
  }

  double res1 = 0, res2 = 0;
  sort(edge1.begin(), edge1.end());
  sort(edge2.begin(), edge2.end());

  for (auto [u, v, w] : edge1) {
    if (join(u, v)) {
      res1 += w;
    }
  }

  dsu.resize(n + 1);
  iota(dsu.begin(), dsu.end(), 0);

  for (auto [u, v, w] : edge2) {
    if (join(u, v)) {
      res2 += w;
    }
  }

  cout << fixed << setprecision(9) << min(res1, res2);
}
