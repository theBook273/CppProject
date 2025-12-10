#include <bits/stdc++.h>

using namespace std;

int n, res = 0, full = (1 << 4) - 1;
int a[401][401];

string toBin(int x) {
  string s;
  for (int i = 0; i < 4; i++) {
    char ins = '0';
    if (x & (1 << i)) {
      ins = '1';
    }
    s.push_back(ins);
  }
  return s;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int x, y, color, i = 0; i < n; i++) {
    cin >> x >> y >> color;
    x += 200;
    y += 200;
    a[x][y] = color;
  }

  for (int y1 = 0; y1 <= 399; y1++) {
    for (int y2 = y1 + 1; y2 <= 400; y2++) {
      vector<int> dem(full + 1, 0);
      for (int x = 0; x <= 400; x++) {
        if (a[x][y1] != 0 && a[x][y2] != 0 && a[x][y1] != a[x][y2]) {
          int comb = (1 << (a[x][y1] - 1)) + (1 << (a[x][y2] - 1));
          // cout << toBin(comb) << " " << toBin(full - comb) << "\n";
          dem[comb]++;
          res += dem[full - comb];
        }
      }
    }
  }

  cout << res;
}
