#include <bits/stdc++.h>

using namespace std;

vector<int> dsu;

struct edge {
  int u, v, len;
  bool operator<(const edge &other) const { return len < other.len; }
};

struct point {
  int x, y, z, id;
};

int parent(int p) { return (dsu[p] == p) ? p : dsu[p] = parent(dsu[p]); }

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;

  vector<point> a(n);
  dsu.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
    a[i].id = i;
    dsu[i] = i;
  }

  vector<edge> gra;

  sort(a.begin(), a.end(),
       [](const point &e, const point &f) { return e.x < f.x; });
  for (int i = 0; i < n - 1; i++) {
    gra.push_back({a[i].id, a[i + 1].id, abs(a[i].x - a[i + 1].x)});
  }

  sort(a.begin(), a.end(),
       [](const point &e, const point &f) { return e.y < f.y; });
  for (int i = 0; i < n - 1; i++) {
    gra.push_back({a[i].id, a[i + 1].id, abs(a[i].y - a[i + 1].y)});
  }

  sort(a.begin(), a.end(),
       [](const point &e, const point &f) { return e.z < f.z; });
  for (int i = 0; i < n - 1; i++) {
    gra.push_back({a[i].id, a[i + 1].id, abs(a[i].z - a[i + 1].z)});
  }

  sort(gra.begin(), gra.end());

  int tong = 0;

  for (auto i : gra) {
    int temp1 = parent(i.u);
    int temp2 = parent(i.v);
    if (temp1 != temp2) {
      dsu[temp1] = temp2;
      tong += i.len;
    }
  }

  cout << tong << "\n";
}
