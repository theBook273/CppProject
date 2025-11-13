#include <bits/stdc++.h>

using namespace std;

int n, s, t;

bool check(int u, int v, int x, int y) {
  return ((x == y && u == v) || (x + y == s && u + v == 0));
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    int u, v, x, y;
    int tong = 0;
    while (n--) {
      cin >> u >> v >> x >> y;
      tong += check(u, v, x, y);
    }
    cout << tong << "\n";
  }
}
