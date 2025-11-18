#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Planet {
  int x, y, z, id;
};

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

vector<Edge> edge;
vector<int> dsu;
vector<Planet> plan;
int n;

bool CompX(Planet a, Planet b) { return a.x < b.x; }
bool CompY(Planet a, Planet b) { return a.y < b.y; }
bool CompZ(Planet a, Planet b) { return a.z < b.z; }

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
bool join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    dsu[x] = y;
    return 1;
  }
  return 0;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;

  dsu.resize(n);
  iota(dsu.begin(), dsu.end(), 0);

  for (int x, y, z, i = 0; i < n; i++) {
    cin >> x >> y >> z;
    plan.push_back({x, y, z, i});
  }

  sort(plan.begin(), plan.end(), CompX);
  for (int i = 0; i < n - 1; i++) {
    Planet &a = plan[i];
    Planet &b = plan[i + 1];
    edge.push_back({a.id, b.id, abs(a.x - b.x)});
  }

  sort(plan.begin(), plan.end(), CompY);
  for (int i = 0; i < n - 1; i++) {
    Planet &a = plan[i];
    Planet &b = plan[i + 1];
    edge.push_back({a.id, b.id, abs(a.y - b.y)});
  }

  sort(plan.begin(), plan.end(), CompZ);
  for (int i = 0; i < n - 1; i++) {
    Planet &a = plan[i];
    Planet &b = plan[i + 1];
    edge.push_back({a.id, b.id, abs(a.z - b.z)});
  }

  int res = 0;
  sort(edge.begin(), edge.end());
  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      res += w;
    }
  }

  cout << res << "\n";
}
