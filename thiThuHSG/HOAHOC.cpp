#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 5;

int n, m, q, l, r;
int a[MAXN];
int pre[MAXN][MAXN];
unordered_map<int, pair<int, int>> good;

signed main() {
  cin.tie()->sync_with_stdio(0);

  // freopen("HOAHOC.inp", "r", stdin);
  // freopen("HOAHOC.out", "w", stdout);

  cin >> n >> m >> q;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int l, r, i = 1; i <= m; i++) {
    cin >> l >> r;
    good[i] = {l, r};
  }

  for (int i = 1; i <= m; i++) {
    pre[i][0] = 0;
    pre[i][1] = (a[1] == i);
    for (int j = 2; j <= n; j++) {
      pre[i][j] = pre[i][j - 1] + (a[j] == i);
    }
  }

  while (q--) {
    int res = 0;
    cin >> l >> r;
    for (int i = 1; i <= m; i++) {
      int temp = pre[i][r] - pre[i][l - 1];
      if (good[i].first <= temp && temp <= good[i].second) {
        res++;
      }
    }
    cout << res << "\n";
  }
}
