#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, q, x, y, c, d;
vector<vector<int>> a, pref;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  a.resize(n + 1, vector<int>(n + 1, 0));
  pref.resize(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char temp;
      cin >> temp;
      if (temp == '*') {
        a[i][j] = 1;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref[i][j] =
          pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + a[i][j];
    }
  }

  while (q--) {
    cin >> x >> y >> c >> d;
    cout << pref[x - 1][y - 1] + pref[c][d] - pref[x - 1][d] - pref[c][y - 1]
         << "\n";
  }
}
