#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("FINDDANTE.INP", "r", stdin);
  freopen("FINDDANTE.OUT", "w", stdout);

  map<int, int> mp;
  int n;
  while (cin >> n) {
    mp[n] += 1;
  }
  int res = -1;
  for (auto [i, j] : mp) {
    if (j % 2 != 0) {
      res = i;
      break;
    }
  }

  cout << res;
}
