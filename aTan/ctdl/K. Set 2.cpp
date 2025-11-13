#include <bits/stdc++.h>
#include <climits>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  multiset<int> se;
  int n;
  cin >> n;
  char type;
  int x;
  while (n--) {
    cin >> type;
    if (type != '?') {
      cin >> x;
      if (type == '+') {
        se.insert(x);
      } else {
        auto it = se.find(x);
        if (it != se.end())
          se.erase(it);
      }
      continue;
    }

    int max1 = -1, max2 = -1, min1 = -1, min2 = -1;

    if (se.empty()) {
      cout << min1 << " " << min2 << " " << max1 << " " << max2 << "\n";
      continue;
    }

    auto i = se.begin();
    auto e = se.end();
    e--;
    min1 = *i;
    max1 = *e;

    if (se.size() >= 2) {
      i = next(i);
      min2 = *i;

      e = prev(e);
      max2 = *e;
    }

    cout << min1 << " " << min2 << " " << max1 << " " << max2 << "\n";
  }
}
