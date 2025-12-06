#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k, res = 0;
vector<vector<int>> a, pref;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  a.resize(n + 1, vector<int>(n + 1, 0));
  pref.resize(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
    }
  }

  for (int i = 1; i + k - 1 <= n; i++) {
    for (int j = 1; j + k - 1 <= n; j++) {
      int i2 = i + k - 1;
      int j2 = j + k - 1;
      int sum =
          pref[i2][j2] + pref[i - 1][j - 1] - pref[i - 1][j2] - pref[i2][j - 1];
      res = max(res, sum);
    }
  }

  cout << res;
}
