#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("GHEP.INP", "r", stdin);
  freopen("GHEP.OUT", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int res = 0;
  for (int i = 0; i < n; i++) {
    int cnt = n - i;
    int side = min(cnt, a[i]);
    res = max(res, side * side);
  }
  cout << res << "\n";
}
