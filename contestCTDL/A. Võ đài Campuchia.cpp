#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> a;

namespace sub1 {

void fight(int l, int r) {
  vector<int> point(n + 5, 0);
  int elec = r - l + 1;
  for (int i = l; i <= r; i++) {
    for (int j = i + 1; j <= r; j++) {
      if (a[i] == a[j]) {
        point[i]++;
        point[j]++;
      } else if (a[j] % a[i] == 0) {
        point[i]++;
      } else if (a[i] % a[j] == 0) {
        point[j]++;
      }
    }
  }
  for (int i = l; i <= r; i++) {
    if (point[i] == r - l) {
      elec--;
    }
  }
  cout << elec << "\n";
}

signed solve() {
  string type;
  int x, y;

  while (q--) {
    cin >> type >> x >> y;
    if (type == "CHANGE") {
      a[x] = y;
    } else {
      fight(x, y);
    }
  };

  return 0;
}

} // namespace sub1

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;

  a.resize(n + 5, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (q <= 1000 && n <= 1000) {
    sub1::solve();
  }
}
