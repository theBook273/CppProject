#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cout.tie()->sync_with_stdio(0);

  int n, m;

  cin >> n >> m;
  set<int> se;
  vector<int> defeated(n + 1, 0), toRM;

  for (int i = 1; i <= n; i++) {
    se.insert(i);
  }

  int x, y, z;
  while (m--) {
    toRM.clear();

    cin >> x >> y >> z;
    auto it = se.lower_bound(x);

    while (it != se.end() && *it <= y) {
      if (*it != z) {
        defeated[*it] = z;
        toRM.push_back(*it);
      }
      ++it;
    }

    for (auto i : toRM) {
      se.erase(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << defeated[i] << " ";
  }
}
