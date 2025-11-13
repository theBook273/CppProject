#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

vector<pair<int, int>> p;
int n, ans = 0;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  for (int x, y, i = 0; i < n; i++) {
    cin >> x >> y;
    p.push_back({x, y});
  }

  sort(p.begin(), p.end());

  // for (auto [x, y] : square) {
  //   cout << x << " " << y << "\n";
  // }

  for (int i = 0; i < n; i++) {
    set<int> se;
    int sumGap = 0;
    se.insert(p[i].second);

    for (int j = i + 1; j < n; j++) {
      int y = p[j].second;

      auto it = se.lower_bound(y);
      bool hasPrev = 0, hasNext = 0;
      int prevY, nextY;

      if (it != se.begin()) {
        hasPrev = 1;
        prevY = *prev(it);
      }
      if (it != se.end()) {
        hasNext = 1;
        nextY = *it;
      }

      if (hasNext && hasPrev) {
        int oldGap = nextY - prevY - 1;
        if (oldGap > 0) {
          sumGap -= oldGap;
        }
      }

      if (hasPrev) {
        int leftGap = y - prevY - 1;
        if (leftGap > 0) {
          sumGap += leftGap;
        }
      }

      if (hasNext) {
        int rightGap = nextY - y - 1;
        if (rightGap > 0) {
          sumGap += rightGap;
        }
      }

      se.insert(y);

      int w = p[j].first - p[i].first - 1;
      if (w > 0 && sumGap > 0) {
        ans = (ans + ((w + 1) % MOD) * ((sumGap + 1) % MOD)) % MOD;
      }
    }
  }

  cout << ans % MOD;
}
