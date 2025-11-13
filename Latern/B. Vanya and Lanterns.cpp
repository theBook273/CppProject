#include <bits/stdc++.h>
#define int double

using namespace std;

int n, l;
vector<int> loc;

bool check(long double d) {
  if (loc[0] - d > 0)
    return false;
  if (loc.back() + d < l)
    return false;

  for (int i = 0; i + 1 < n; i++) {
    if (loc[i] + d < loc[i + 1] - d)
      return false;
  }
  return true;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> l;
  loc.resize(n);
  for (auto &i : loc) {
    cin >> i;
  }
  sort(loc.begin(), loc.end());

  int res = 0;
  int l = 0, r = 1e9, m;
  for (int i = 1; i <= 1000; i++) {
    m = (l + r) / 2;
    if (check(m)) {
      res = m;
      r = m;
    } else {
      l = m;
    }
  }
  cout << fixed << setprecision(10) << res;
}
