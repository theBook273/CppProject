#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct line {
  int id, time, state;
  bool operator<(const line &b) {
    if (time != b.time) {
      return time < b.time;
    }
    return state < b.state;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<line> event;

  for (int l, r, i = 0; i < n; i++) {
    cin >> l >> r;
    event.push_back({i, l, +1});
    event.push_back({i, r, -1});
  }

  sort(event.begin(), event.end());

  for (auto [x, y, z] : event) {
    cout << x << " " << y << " " << z << "\n";
  }
}
