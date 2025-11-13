#include <bits/stdc++.h>

using namespace std;

int n, ax, bx, cx, ay, by, cy;

int gocPhanTu(int x, int y) {
  if (x < ax && y < ay) {
    return 1;
  } else if (x < ax && y > ay) {
    return 2;
  } else if (x > ax && y > ay) {
    return 3;
  } else {
    return 4;
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;

  if (gocPhanTu(bx, by) == gocPhanTu(cx, cy)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
