#include <bits/stdc++.h>
#define val first
#define color second
#define int long long

using namespace std;

vector<pair<int, int>> points;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int c, i = 0; i < n; i++) {
    cin >> c;
    points.push_back({c, 1});
  }

  for (int c, i = 0; i < n; i++) {
    cin >> c;
    points.push_back({c, 0});
  }

  sort(points.begin(), points.end());

  int res = 0;

  for (int i = 0; i < (int)points.size(); i++) {
    if (i + 1 < (int)points.size()) {
      if (points[i].color != points[i + 1].color) {
        res++;
        i++;
      }
    }
  }

  cout << res;
}
