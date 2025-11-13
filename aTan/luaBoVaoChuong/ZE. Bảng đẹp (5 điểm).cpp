#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m, res = 0;
  cin >> n >> m;
  int a[505][505];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      a[i][j] %= 9;
    }
  }

  int pref[505][505];
  memset(pref, 0, sizeof(pref));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] = (pref[i - 1][j] + a[i][j]) % 9;
    }
  }

  for (int top = 1; top <= n; top++) {
    for (int bot = top; bot <= n; bot++) {
      vector<int> cnt(9, 0);
      int cur = 0;
      cnt[0] = 1;

      for (int j = 1; j <= m; j++) {
        int colSum = (pref[bot][j] - pref[top - 1][j] + 9) % 9;
        cur = (cur + colSum) % 9;
        res += cnt[cur];
        cnt[cur]++;
      }
    }
  }

  cout << res;
}
