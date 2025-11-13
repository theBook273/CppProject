#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);

  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  sort(a.begin(), a.end());
  int res = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      int mark = -1;
      for (int j = i + 1; j < n; j++) {
        if (a[j] != 0 && a[i] + a[j] <= x) {
          mark = max(mark, j);
        }
      }
      a[i] = 0;
      if (mark != -1) {
        a[mark] = 0;
      }
      res++;
    }
  }

  cout << res;
}
