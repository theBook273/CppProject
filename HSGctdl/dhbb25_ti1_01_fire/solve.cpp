#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> height, cost;

namespace sub1 {

signed solve() { return 0; }

} // namespace sub1

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  height.resize(n, 0);

  for (auto &i : height) {
    cin >> i;
  }

  int temp = 0;

  cost.resize(n - 1, 0);
  for (auto &i : height) {
    cin >> i;
    temp += i;
  }

  if (n < 15 && k < 15 && temp == n - 1) {
    return sub1::solve();
  }
}
