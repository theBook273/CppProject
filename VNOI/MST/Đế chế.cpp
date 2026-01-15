#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Point {
  int x, y, z, id;
};

struct Edge {
  int from, to, len;
  const bool operator<(const Edge &other) { return len < other.len; }
};

int n, matched = 0, res = 0;
vector<Point> point;
vector<Edge> edge;
vector<int> dsu;

bool compX(Point &a, Point &b) { return a.x < b.x; }
bool compY(Point &a, Point &b) { return a.y < b.y; }
bool compZ(Point &a, Point &b) { return a.z < b.z; }

int acs(int x) { return (dsu[x] == x ? x : dsu[x] = acs(dsu[x])); }
bool join(int x, int y) {
  x = acs(x);
  y = acs(y);
  if (x != y) {
    dsu[x] = y;
    return 1;
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  dsu.resize(n);
  iota(dsu.begin(), dsu.end(), 0);

  for (int x, y, z, i = 0; i < n; i++) {
    cin >> x >> y >> z;
    point.push_back({x, y, z, i});
  }

  sort(point.begin(), point.end(), compX);
  for (int i = 0; i < n - 1; i++) {
    auto p1 = point[i];
    auto p2 = point[i + 1];
    edge.push_back({p1.id, p2.id, abs(p1.x - p2.x)});
  }

  sort(point.begin(), point.end(), compY);
  for (int i = 0; i < n - 1; i++) {
    auto p1 = point[i];
    auto p2 = point[i + 1];
    edge.push_back({p1.id, p2.id, abs(p1.y - p2.y)});
  }

  sort(point.begin(), point.end(), compZ);
  for (int i = 0; i < n - 1; i++) {
    auto p1 = point[i];
    auto p2 = point[i + 1];
    edge.push_back({p1.id, p2.id, abs(p1.z - p2.z)});
  }

  sort(edge.begin(), edge.end());

  for (auto [u, v, w] : edge) {
    if (join(u, v)) {
      res += w;
      matched++;
      if (matched == n - 1) {
        break;
      }
    }
  }

  cout << res;
}
