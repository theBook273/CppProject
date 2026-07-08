#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  freopen("TEST.INP", "r", stdin);
  freopen("SOLVE.OUT", "w", stdout);

  int t;
  cin >> t;
  vector<int> a(3);
  string res[] = {"NO\n", "YES\n"};
  while (t--) {
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end(), greater<int>());
    cout << res[a[0] == a[1] + a[2]];
  }
}
