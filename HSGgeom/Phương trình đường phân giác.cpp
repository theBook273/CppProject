#include <bits/stdc++.h>

using namespace std;

struct point {
  double x, y;
};

struct vec {
  double x, y;
  vec fromTo(point a, point b) {
    vec res;
    res.x = b.x - a.x;
    res.y = b.y - a.y;
    return res;
  }
};

struct line {
  double a, b, c;
};

double len(vec a) { return sqrt(a.x * a.x + a.y * a.y); }

vec chuaHoa(vec a) { return {a.x / len(a), a.y / len(a)}; }

vec sum(vec a, vec b) { return {a.x + b.x, a.y + b.y}; }

line qua2Diem(point p1, vec vtpt) {
  line res;
  res.a = vtpt.x;
  res.b = vtpt.y;
  res.c = vtpt.x * -p1.x + vtpt.y * -p1.y;
  return res;
}

signed main() {
  point a, b, c;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cin >> c.x >> c.y;

  vec v1, v2;
  v1 = v1.fromTo(a, b);
  v2 = v2.fromTo(a, c);
  v1 = chuaHoa(v1);
  v2 = chuaHoa(v2);

  vec vmid = sum(v1, v2);
  point mid = {a.x + vmid.x, a.y + vmid.y};

  vec vtcp;
  vtcp = vtcp.fromTo(a, mid);
  vec vtpt = {vtcp.y / vtcp.x, -1};

  line res = qua2Diem(a, vtpt);
  cout << fixed << setprecision(9) << res.a << " " << res.b << " " << res.c;
}
